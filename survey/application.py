import cs50
import csv

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


list_of_countries = []
with open("countries", "r") as file:
    for line in file:
        list_of_countries.append(line)


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")


@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html", countries=list_of_countries)


@app.route("/form", methods=["POST"])
def post_form():
    first_name = request.form.get("first_name")
    last_name = request.form.get("last_name")
    sex = request.form.get("sex")
    school = request.form.get("school")
    country = request.form.get("country")

    if not (first_name and last_name and school and sex and country):
        message = "Inputs missing\nPlease, make sure to provide all the inputs."
        return render_template("error.html", message=message)

    with open('survey.csv', 'a') as file:
        writer = csv.DictWriter(file, fieldnames=["First Name", "Last Name", "Sex", "School", "Country"])
        writer.writerow({"First Name": first_name, "Last Name": last_name, "Sex": sex, "School": school, "Country": country})

    return redirect("/sheet")


@app.route("/sheet", methods=["GET"])
def get_sheet():
    registers = []
    with open("survey.csv") as file:
        for line in file:
            person = line.strip().split(',')
            registers.append(person)
    return render_template("registered.html", registers=registers)

