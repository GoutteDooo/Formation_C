from cs50 import get_int

n = get_int("Number: ")

# Luhn's Algorithm
def luhn(n):
  sum = 0
  for i in range(16, 0, -1):
    n = n / 10
    digit = n % 10
    digit *= 2
    sum += digit
    n = n / 10
    print("n: ", n)
    print("digit: ", digit)
    print("sum: ", sum)
  return sum % 10 == 0

if luhn(n):
  print("Valid")
else:
  print("Invalid")