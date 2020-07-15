from cs50 import get_string

text = get_string("Text: ")
letters = 0
words = 1
sentences = 0
spaces = 0

for i in range(len(text)):
    if (text[i] >= "a" and text [i] <= "z") or (text[i] >= "A" and text [i] <= "Z"):
        letters += 1

for i in range(len(text)):
    if text[i] == " ":
        spaces += 1

for q in range(len(text)):
    if text[q] == " " and text[q + 1] != " ":
        words += 1

for a in range(len(text)):
    if text[a] == "." or text[a] == "!" or text[a] == "?":
        sentences += 1

L = float((letters * 100) / words)
S = float((sentences * 100) / words)

grade = round(float(0.0588 * L - 0.296 * S - 15.8))

if grade <= 1:
    print("Before Grade 1\n")

if grade > 1 and grade < 16:
    print(f"Grade {grade} \n")

if grade >= 16:
    print("Grade 16+\n")
