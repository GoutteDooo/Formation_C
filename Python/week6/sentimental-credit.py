from cs50 import get_int

n = get_int("Number: ")

# Luhn's Algorithm
def luhn(n):
  numbers = [int(x) for x in str(n)]
  sum = 0

  for i in range(len(numbers)-1, -1, -1):
    if i % 2 != 0:
      sum += numbers[i]
    else:
      if numbers[i] > 9:
        sum += numbers[i] * 2 - 9
      else:
        sum += numbers[i] * 2
    print("sum: ", sum)
  print("sum: ", sum)
  return sum % 10 == 0

if luhn(n):
  print("Valid")
else:
  print("Invalid")

# 4003600000000014