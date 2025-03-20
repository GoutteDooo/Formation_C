from cs50 import get_int

n = get_int("Number: ")

# Luhn's Algorithm
def luhn(n):
  sum = 0
  length = len(str(n))
  for i in range(length, 0, -2):
    n = int(n / 10)
    digit = n % 10
    digit *= 2
    sum += digit
    n = int(n / 10)
    print("n: ", n)
    print("digit: ", digit)
    print("sum: ", sum)
  return sum % 10 == 0

if luhn(n):
  print("Valid")
else:
  print("Invalid")

# 4003600000000014