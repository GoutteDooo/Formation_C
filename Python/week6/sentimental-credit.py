from cs50 import get_int

n = get_int("Number: ")

# Luhn's Algorithm
def luhn(n):
  sum = 0
  for i in range(n, 0, -1):
    digit = n.lastdigit()
    if i % 2 == 1:
      digit *= 2
    if digit > 9:
      digit -= 9
    sum += digit
  return sum % 10 == 0

if luhn(n):
  print("Valid")
else:
  print("Invalid")