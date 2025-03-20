from cs50 import get_int

n = get_int("Number: ")

# Luhn's Algorithm
def luhn(n):
  numbers = [int(x) for x in str(n)]
  sum = 0

  for i in range(len(numbers)-1, 0, -2):
    if numbers[i] > 9:
      sum += numbers[i] - 9
    else:
      sum += numbers[i] * 2
  for i in range(len(numbers), 0, -2):
    sum += numbers[i]

if luhn(n):
  print("Valid")
else:
  print("Invalid")

# 4003600000000014