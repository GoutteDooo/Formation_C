from cs50 import get_int

while True:
  height = get_int("Height: ")
  if height > 0 and height < 9:
    break

blocks = ""

for i in range(height):
  blocks += "#"
  print(" " * (height - i - 1) + blocks + "  " + blocks)
