from sys import argv, exit

if len(argv) != 2:
  print("Missing CLA.")
  exit(1)

print(f"Hello, {argv[1]}")
exit(0)