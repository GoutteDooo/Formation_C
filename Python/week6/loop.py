for i in range(ord('a'),ord('z'),5):
  print(i)

phrase = "You're off to Great Places"

for i in range(len(phrase)):
  print(phrase[i], end=" ")
print(end="!!!!\n")
print(phrase, sep=".", end="!!!!\n")