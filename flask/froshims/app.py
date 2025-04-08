from flask import Flask, render_template, request

app = Flask(__name__)

SPORTS=[
  "Basketball",
  "Soccer",
  "Baseball"
]

REGISTRANTS = {
  
}


@app.route('/')
def index():
  return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
  
  name = request.form.get("name")
  if not name:
    return render_template("error.html", message="You must enter a name")
  
  sport = request.form.get("sport")
  if not sport:
    return render_template("error.html", message="You must choose a sport")
  if sport not in SPORTS:
    return render_template("error.html", message="Invalid sport")

  return render_template("success.html")