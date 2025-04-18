import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, jsonify
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd
from datetime import datetime

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    #get all stocks
    #get current datas of all companies which are in the history table of the user
    user_shares = db.execute("SELECT symbol, shares FROM stocks WHERE user_id = ?", session["user_id"])  
    #stock this data in a dictionary with the following format :
    # {'company':company, 'symbol':symbol, 'shares':shares, 'price':price, 'total_holdings':total_holdings}
    stocks = []
    all_total_holdings = 0
    #for all symbols
    for i in range(len(user_shares)):
        # do this for all companies in the history table of the user
        shares_data = lookup(user_shares[i]["symbol"])
        stock = {}
        stock["company"] = shares_data["name"]
        stock["symbol"] = shares_data["symbol"]
        stock["shares"] = user_shares[i]["shares"]
        stock["price"] = usd(shares_data["price"])
        stock["total_holdings"] = usd(round((shares_data["price"] * user_shares[i]["shares"]),2))
        stocks.append(stock)
        #get all total holdings
        all_total_holdings += round((shares_data["price"] * user_shares[i]["shares"]),2)

    #get the cash balance of the user
    user_cash = round(db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"],2)

    all_total_holdings = round(all_total_holdings,2)
    return render_template("index.html", stocks=stocks, user_cash=usd(user_cash), all_total_holdings=all_total_holdings)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        #get value from the market
        s_looked_up = lookup(symbol)
        username = db.execute("SELECT username FROM users WHERE id = ?", session["user_id"])[0]["username"]
        if not symbol:
            return apology("must provide symbol", 400)
        if not s_looked_up:
            return apology("invalid symbol", 400)

        shares = request.form.get("shares")
        try:
            shares = int(shares)
        except:
            return apology("must provide an integer", 400)

        if shares < 0: 
            return apology("must provide positive shares", 400)
        
        #Verify if user has enough money for the buy
        try:
            user_money = db.execute("SELECT cash FROM users WHERE username = ?", username)[0]["cash"]
        except:
            return apology("Sorry, an error occured when getting your money", 400)

        share_price = s_looked_up["price"]
        buy_cost = round((int(shares) * share_price),2)

        if user_money < buy_cost:
            # if it is not the case, return an apology
            return apology("Sorry, you don't have enough money to buy this stock", 400)

        # If it is the case, save the buy into history table and update user's money into users table
        date = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        try:
            db.execute("INSERT INTO history (username, shares, symbol, stockprice, total_transaction, date, user_id, type) VALUES (?, ?, ?, ?, ?, ?, ?, ?)", username, int(shares), symbol.upper(), share_price, buy_cost, date, session["user_id"], "buy")
        except:
            return apology("Sorry, an error occured during the purchase", 400)
        
        try:
            db.execute("UPDATE users SET cash = cash - ? WHERE username = ?", buy_cost, username)
        except:
            db.execute("DELETE FROM history WHERE date = ? AND username = ?", date, username)
            return apology("Sorry, an error occured when updating your account", 400)

        #insert new stock into stocks table
        #if symbol already exist for user, update the shares
        #else, insert new stock
        try:
            rows = db.execute("SELECT * FROM stocks WHERE user_id = ? AND symbol = ?", session["user_id"], symbol.upper())
            if len(rows) == 0:
                db.execute("INSERT INTO stocks (user_id, username, symbol, shares) VALUES (?, ?, ?, ?)", session["user_id"], username, symbol.upper(), int(shares))
            else:
                db.execute("UPDATE stocks SET shares = shares + ? WHERE user_id = ? AND symbol = ?", int(shares), session["user_id"], symbol.upper())
        except:
            db.execute("UPDATE users SET cash = cash + ? WHERE username = ?", buy_cost, username)
            db.execute("DELETE FROM history WHERE date = ? AND username = ?", date, username)
            return apology("Sorry, an error occured when inserting your stock", 400)
        
        return redirect("/")

    #if "GET"
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    history = db.execute("SELECT * FROM history WHERE user_id = ?", session["user_id"])
    for i in range(len(history)):
        history[i]["total_transaction"] = usd(history[i]["total_transaction"])
        history[i]["stockprice"] = usd(history[i]["stockprice"])
    return render_template("history.html", history=history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("must provide symbol", 400)
        
        quote = lookup(symbol)
        if not quote:
            return apology("invalid symbol", 400)

        quote["price"] = usd(quote["price"])
        
        return render_template("quoted.html", quotes=quote)
    
    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        if not username:
            return apology("must provide username", 400)
        if not password or not confirmation:
            return apology("must provide password", 400)
        if password != confirmation:
            return apology("password and confirmation password do not match", 400)

        try:
            db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, generate_password_hash(password))
            # db.execute will raise a ValueError if username already exists
        except ValueError:
            print("Username already exist!")
            return apology("username already exist", 400)
        except:
            print("Error while registering user!")
            return apology("Sorry, an error occured", 400)
        else:
            print("User registered successfully!")
            return redirect("/")
    
    return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    username = db.execute("SELECT username FROM users WHERE id = ?", session["user_id"])[0]["username"]

    #get list of all symbols buyed by the user
    try:
        user_symbols = db.execute("SELECT DISTINCT symbol FROM stocks WHERE username = ?", username)
    except:
        return apology("Sorry, an error occured", 400)

    if request.method == "POST":
        symbol = request.form.get("symbol")
        #Verify if symbol exists
        if not symbol:
            #If not, return an apology
            return apology("must provide symbol", 400)

        #Verify if symbol is in the history table of the user
        if symbol.lower() not in [item["symbol"].lower() for item in user_symbols]:
            #If not, return an apology
            return apology("Symbol doesn't exist in your purchases", 400)
        
        #Verify if positive shares are provided
        shares = int(request.form.get("shares"))
        if type(shares) != int:
            return apology("Hmm... looks like you didn't provide an integer", 400)

        if shares < 0:
            return apology("must provide positive shares", 400)
        
        #And if the user has enough shares
        try:
            user_shares = db.execute("SELECT shares FROM stocks WHERE username = ? AND symbol = ?", username, symbol.upper())[0]['shares']
        except:
            return apology("Sorry, an error occured when getting your shares", 400)

        if user_shares < shares:
            return apology("Sorry, you don't have enough shares to sell this stock", 400)


        #calculate the sum of shares sold
        look_up = lookup(symbol)
        sold = round(look_up["price"] * shares, 2)
        date = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

        #Insert new sell into history table
        try:
            db.execute("INSERT INTO history (username, shares, symbol, stockprice, total_transaction, date, user_id, type) VALUES (?, ?, ?, ?, ?, ?, ?, ?)", username, shares, symbol.upper(), look_up["price"], sold, date, session["user_id"], "sell")
        except:
            return apology("Sorry, an error occured when inserting your sell", 400)

        #give cash back to the user first (if not, the operation will fail)
        try:
            db.execute("UPDATE users SET cash = cash + ? WHERE username = ?", sold, username)
        except:
            db.execute("DELETE FROM history WHERE date = ? AND username = ?", date, username)
            return apology("Sorry, an error occured when updating your account", 400)
        
        #When all conditions have passed, delete the amount of shares from the stocks table
        #if all shares are sold, delete the stock from the stocks table
        #else, update the shares of the stock
        if shares == user_shares:
            try:
                db.execute("DELETE FROM stocks WHERE user_id = ? AND symbol = ?", session["user_id"], symbol.upper())
            except:
                db.execute("DELETE FROM history WHERE date = ? AND username = ?", date, username)
                db.execute("UPDATE users SET cash = cash - ? WHERE username = ?", sold, username)
                return apology("Sorry, an error occured when deleting your stock", 400)
        else:
            try:
                db.execute("UPDATE stocks SET shares = shares - ? WHERE user_id = ? AND symbol = ?", shares, session["user_id"], symbol.upper())
            except:
                db.execute("DELETE FROM history WHERE date = ? AND username = ?", date, username)
                db.execute("UPDATE users SET cash = cash - ? WHERE username = ?", sold, username)
                return apology("Sorry, an error occured when updating your stock", 400)

        return redirect("/")

    return render_template("sell.html", user_symbols=user_symbols)


@app.route("/password", methods=["GET", "POST"])
@login_required
def password():
    """Change password"""
    if request.method == "POST":
        old_password = request.form.get("old_password")
        new_password = request.form.get("new_password")
        confirmation = request.form.get("confirmation")
        if not old_password:
            return apology("must provide old password", 403)
        if not new_password or not confirmation:
            return apology("must provide new password", 403)
        if new_password != confirmation:
            return apology("password and confirmation password do not match", 403)

        try:
            db.execute("UPDATE users SET hash = ? WHERE id = ?", generate_password_hash(new_password), session["user_id"])
        except:
            return apology("Sorry, an error occured when updating your password", 403)
        else:
            return redirect("/")
    
    return render_template("password.html")

@app.route("/addfunds", methods=["POST"])
@login_required
def addfunds():
    """Add funds to user's account"""
    if request.method == "POST":
        value = request.json["value"]
        if int(value) < 0:
            return apology("must provide positive value", 403)

        try:
            db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", value, session["user_id"])
        except:
            return apology("Sorry, an error occured when updating your account", 403)
        else:
            return jsonify({"message": "Funds added successfully !"})
    
    return jsonify({"message": "Invalid request"})