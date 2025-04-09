import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
            
        name = request.form.get("friend")
        if not name:
            return redirect("/")

        month = request.form.get("month")
        if not month:
            return redirect("/")

        day = request.form.get("day")
        if not day:
            return redirect("/")

        db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", name, month, day)
        return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html
        birthdays = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", bdays=birthdays)


@app.route("/delete", methods=["POST"])
def delete():
    name = request.form.get("friend")
    month = request.form.get("month")
    day = request.form.get("day")
    db.execute("DELETE FROM birthdays WHERE name = ? AND month = ? AND day = ?", name, month, day)
    return redirect("/")

@app.route("/update", methods=["POST"])
def update():
    data = request.get_json()
    id = data["id"]
    name = data["name"]
    date = data["birthday"]
    print(id,name,date)
    day = date.split("/")[1]
    month = date.split("/")[0]
    db.execute("UPDATE birthdays SET name = ?, month = ?, day = ? WHERE id = ?", name, month, day, id)
    return jsonify({"success": True})