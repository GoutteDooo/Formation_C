from cs50 import get_int

cards = {
  "AMEX": [34,37],
  "MASTERCARD": [51,52,53,54,55],
  "VISA": [4],
}

n = get_int("Number: ")
numbers = [int(x) for x in str(n)]

# Luhn's Algorithm
def luhn(n):
  sum = 0
  step = 0
  for i in range(len(numbers)-1, -1, -1):
    if step % 2 == 0:
      sum += numbers[i]
    else:
      if numbers[i] * 2 > 9:
        sum += numbers[i] * 2 - 9
      else:
        sum += numbers[i] * 2
    print("sum: ", sum)
    step += 1 
  print("sum: ", sum)
  return sum % 10 == 0

if luhn(numbers):
  if int(str(numbers[0])+str(numbers[1])) in cards["AMEX"]:
    print("AMEX")
  elif int(str(numbers[0])+str(numbers[1])) in cards["MASTERCARD"]:
    print("MASTERCARD")
  elif int(str(numbers[0])) in cards["VISA"]:
    print("VISA")
  else:
    print("Invalid")


# 4003600000000014