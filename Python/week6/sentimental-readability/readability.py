from cs50 import get_string

inpute = "One Fish. Two Fish. Red Fish. Blue Fish."
# text = get_string("Text: ")
text = inpute

# counts number of words
words = text.split()
words = [words.isalpha() for word in words]
# counts number of characters

# counts number of sentences

print(words)