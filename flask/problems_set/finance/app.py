import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
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
    #get current datas of all companies which are in the purchases table of the user
    user_shares = db.execute("SELECT symbol, SUM(shares) as shares FROM purchases WHERE user_id = ? GROUP BY symbol", session["user_id"])
    #stock this data in a dictionary with the following format :
    # {'company':company, 'symbol':symbol, 'shares':shares, 'price':price, 'total_holdings':total_holdings}
    stocks = []
    #for all symbols
    for i in range(len(user_shares)):
        # do this for all companies in the purchases table of the user
        shares_data = lookup(user_shares[i]["symbol"])
        stock = {}
        stock["company"] = shares_data["name"]
        stock["symbol"] = shares_data["symbol"]
        stock["shares"] = user_shares[i]["shares"]
        stock["price"] = shares_data["price"]
        stock["total_holdings"] = round((stock["price"] * user_shares[i]["shares"]),2)
        stocks.append(stock)

    #get the cash balance of the user
    user_cash = round(db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"],2)

    #get all total holdings
    #Do the sum of all total_holdings of the stocks
    all_total_holdings = 0
    for i in range(len(stocks)):
        all_total_holdings += stocks[i]["total_holdings"]
    all_total_holdings = round(all_total_holdings,2)
    return render_template("index.html", stocks=stocks, user_cash=user_cash, all_total_holdings=all_total_holdings)


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
            return apology("must provide symbol", 403)
        if not s_looked_up:
            return apology("invalid symbol", 403)

        shares = request.form.get("shares")
        if int(shares) < 0:
            return apology("must provide positive shares", 403)
            
        #Verify if user has enough money for the buy
        try:
            user_money = db.execute("SELECT cash FROM users WHERE username = ?", username)[0]["cash"]
        except:
            return apology("Sorry, an error occured", 403)

        share_price = s_looked_up["price"]
        buy_cost = round((int(shares) * share_price),2)

        if user_money < buy_cost:
            # if it is not the case, return an apology
            return apology("Sorry, you don't have enough money to buy this stock", 403)

        # If it is the case, save the buy into purchases table and update user's money into users table
        date = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        try:
            db.execute("INSERT INTO purchases (username, shares, symbol, stockprice, total_purchase, date, user_id) VALUES (?, ?, ?, ?, ?, ?, ?)", username, int(shares), symbol, share_price, buy_cost, date, session["user_id"])
        except:
            return apology("Sorry, an error occured during the purchase", 403)
        
        try:
            db.execute("UPDATE users SET cash = cash - ? WHERE username = ?", buy_cost, username)
        except:
            db.execute("DELETE FROM purchases WHERE date = ? AND username = ?", date, username)
            return apology("Sorry, an error occured when updating your account", 403)

        return redirect("/")

    #if "GET"
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


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
            return apology("must provide symbol", 403)
        return render_template("quoted.html", quotes=lookup(symbol))
    
    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        if not username:
            return apology("must provide username", 403)
        if not password or not confirmation:
            return apology("must provide password", 403)
        if password != confirmation:
            return apology("password and confirmation password do not match", 403)

        try:
            db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, generate_password_hash(password))
            # db.execute will raise a ValueError if username already exists
        except ValueError:
            print("Username already exist!")
            return apology("username already exist", 403)
        except:
            print("Error while registering user!")
            return apology("Sorry, an error occured", 403)
        else:
            print("User registered successfully!")
            return redirect("/")
    
    return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        username = db.execute("SELECT username FROM users WHERE id = ?", session["user_id"])[0]["username"]
        #Verify if symbol exists
        if not symbol:
            #If not, return an apology
            return apology("must provide symbol", 403)

        #Verify if symbol is in the purchases table of the user
        try:
            user_symbols = db.execute("SELECT DISTINCT symbol FROM purchases WHERE username = ?", username)
        except:
            return apology("Sorry, an error occured", 403)
        
        if symbol not in user_symbols:
            #If not, return an apology
            return apology("Symbol doesn't existe in your purchases", 403)
            
        return apology("TODO - sell")
    return apology("TODO")
