s = input("Do u agree? ").lower()
t = s.lower()

if t in ["y","yes"]:
  print("Agreed.")
elif t in ["n","no"]:
  print("Not agreed.")