from cs50 import get_string

inpute = "One Fish. Two Fish. Red Fish. Blue Fish."
# text = get_string("Text: ")
text = inpute

# counts number of words
words = text.split()
words = [''.join(char for char in word if char.isalpha()) for word in words]
sum_letters = sum(len(word) for word in words)
L = sum_letters

# counts number of characters


# counts number of sentences
sum_words = (len(words))
sum_sentences = (len(text.split(".")) - 1)
S = 100 * sum_sentences / sum_words

print(L)