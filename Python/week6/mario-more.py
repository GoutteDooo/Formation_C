from cs50 import get_int

height = get_int("Height: ")
blocks = ""

for i in range(height):
  blocks += "#"
  print(" " * (height - i - 1) + blocks + "  " + blocks)
