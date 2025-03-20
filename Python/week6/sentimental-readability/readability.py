from cs50 import get_string

inpute = "One Fish. Two Fish. Red Fish. Blue Fish."
# text = get_string("Text: ")
text = inpute

# counts number of words
words = text.split()
words = [''.join(char for char in word if char.isalpha()) for word in words]
sum_letters = sum(len(word) for word in words) / len(words)


# counts number of characters

# counts number of sentences

print(sum_letters)