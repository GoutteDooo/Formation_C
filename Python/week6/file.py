import csv

with open("phonebook.csv") as file:
  file_reader = csv.DictReader(file)
  for row in file_reader:
    print(row)