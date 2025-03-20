from cs50 import get_string

inpute = "One Fish. Two Fish. Red Fish. Blue Fish."
# inpute = "Would you like them here or there? I would not like them here or there. I would not like them anywhere."
# text = get_string("Text: ")
text = inpute

# counts number of words
words = text.split()
words = [''.join(char for char in word if char.isalpha()) for word in words]
sum_letters = sum(len(word) for word in words)
L = 100 * sum_letters / len(words)

# counts number of characters


# counts number of sentences
sum_words = (len(words))
sum_sentences = (len(text.split(".")))
# get rid of blank items
sum_sentences = [x for x in sum_sentences if x != 0]
S = 100 * (sum_sentences) / (sum_words)

print(sum_sentences)
print(L, S)
ColemanLiauIndex = ((0.0588 * L) - (0.296 * S) - 15.8)
print(round(ColemanLiauIndex))