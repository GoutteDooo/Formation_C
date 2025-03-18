"""
names = ["Yuliia","David","John"]

name = input("Name: ")

if name in names:
  print("Found!")
else:
  print(":(... Not found.")
"""

"""
people = [
  {
    "name": "Yuliia",
    "number": "+1165546875",
  },
  {
    "name": "David",
    "number": "+1486547564",
  },
  {
    "name": "John",
    "number": "+1687654782",
  }
]
name = input("Name: ")
for person in people:
  if person["name"] == name:
    print(f"Phone: {person["number"]}")
    break
else:
  print("Not found :(...")
"""

"""
people = {
  "Yuliia": "+1165546875",
  "David": "+1486547564",
  "John": "+1687654782"
}
name = input("Name: ")
if name in people:
  print(f"Number: {people[name]}")
else:
  print("Not")"""

import csv

name = input("Name: ")
number = input("Number: ")

with open("phonebook.csv", "a") as file:
  writer = csv.DictWriter(file, fieldnames=["name","number"])
  writer.writerow({"name": name, "number": number})