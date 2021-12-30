LANGUAGE_LETTER = 'b'
VOWELS = ('a', 'e', 'i', 'o', 'u')



sentence = input("Enter a sentence:\n")
sentence_in_language = ''.join([l + LANGUAGE_LETTER + l if l in VOWELS else l for l in sentence])
print(sentence_in_language)
