from cs50 import get_int

n = get_int("Number: ")

# Luhn's Algorithm
def luhn(n):
  numbers = [int(x) for x in str(n)]
  print(numbers)

if luhn(n):
  print("Valid")
else:
  print("Invalid")

# 4003600000000014