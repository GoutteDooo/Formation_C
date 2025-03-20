from cs50 import get_int

height = get_int("Height: ")
right_blocks = " "

for i in range(height):
  right_blocks += "#"
  print(right_blocks)
