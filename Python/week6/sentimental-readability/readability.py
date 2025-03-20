from cs50 import get_string
import re

text = get_string("Text: ")

# counts number of words
words = text.split()
words = [''.join(char for char in word if char.isalpha()) for word in words]
sum_letters = sum(len(word) for word in words)
L = 100 * sum_letters / len(words)

# counts number of characters


# counts number of sentences
sum_words = (len(words))

# get rid of blank items
sentences = re.split(r"[.!?]", text)
print("sentences: ",sentences)
sum_sentences = len([s for s in sentences if s.strip() + " "])
print("sum_sentences: ",sum_sentences)
S = 100 * (sum_sentences) / (sum_words)

ColemanLiauIndex = ((0.0588 * L) - (0.296 * S) - 15.8)

print(S, L)

if ColemanLiauIndex < 0:
  print("Before Grade 1")
elif ColemanLiauIndex >= 0 and ColemanLiauIndex < 16:
  print("Grade", round(ColemanLiauIndex))
else:
  print("Grade 16+")
