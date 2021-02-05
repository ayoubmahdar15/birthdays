from cs50 import get_string

text = get_string("Text: ")

## variables set
letters = 0
words = 1
sentences = 0

## Go through each character in text
for element in range(0, len(text)):
    if text[element].isalpha()==True:
        letters += 1
    if text[element].isspace()==True:
        words = words + 1
    if text[element] == "." or text[element] == "?" or text[element] == "!":
        sentences += 1

L = (letters / words) * 100
S = (sentences / words) * 100

## Formula and Print Grade 
grade_index = round(0.0588 * L - 0.296 * S - 15.8)
if grade_index < 1:
    print ("Before Grade 1")
elif grade_index < 16 and grade_index >= 1:
    print (f"Grade {grade_index}")
else:
    print ("Grade 16+")
    