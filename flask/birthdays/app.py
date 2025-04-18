from cs50 import SQL
from flask import Flask, render_template, request, redirect

db = SQL("sqlite:///birthdays.db")

app = Flask(__name__)


@app.route('/', methods=["GET","POST"])
def index():
  if request.method == "POST":

    friend_name = request.form.get("friend")
    if not friend_name:
      return redirect("/")

    month = request.form.get("month")
    if not month:
      return redirect("/")
    day = request.form.get("day")
    if not day:
      return redirect("/")
    
    db.execute("INSERT INTO birthdays (friend, month, day) VALUES (?, ?, ?)", friend_name, month, day)
    return redirect("/")
  else:
    birthdays = db.execute("SELECT * FROM birthdays")
    return render_template("index.html", birthdays=birthdays)