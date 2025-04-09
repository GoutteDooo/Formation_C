from cs50 import SQL
from flask import Flask, render_template, request

db = SQL("sqlite:///birthdays.db")

app = Flask(__name__)


@app.route('/')
def index():
  friend = request.form.get("friend")
  month = request.form.get("month")
  day = request.form.get("day")
  return render_template("index.html")