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
    step += 1 
  return sum % 10 == 0

if luhn(numbers):
  if int(str(numbers[0])+str(numbers[1])) in cards["AMEX"] and len(numbers) == 15:
    print("AMEX")
  elif int(str(numbers[0])+str(numbers[1])) in cards["MASTERCARD"] and len(numbers) == 16 :
    print("MASTERCARD")
  elif int(str(numbers[0])) in cards["VISA"] and (len(numbers) == 13 or len(numbers) == 16):
    print("VISA")
  else:
    print("INVALID")
else:
  print("INVALID")


# 4003600000000014