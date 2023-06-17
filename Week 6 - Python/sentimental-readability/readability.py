from cs50 import get_string


def main():
    text = get_string("Text : ")
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)
    L = float(letters) / float(words) * 100
    S = float(sentences) / float(words) * 100
    grade = (0.0588 * L) - (0.296 * S) - 15.8
    if grade < 1 or grade > 15:
        grade = check_grade(grade)
    else:
        print(f"Grade {int(round(grade))}")


def count_letters(text):
    letters = 0
    for char in text:
        if char.isalpha():
            letters += 1
    return (letters)


def count_words(text):
    words = 1
    for char in text:
        if char == ' ':
            words += 1
    return (words)


def count_sentences(text):
    sentences = 0
    for char in text:
        if char == '.' or char == '!' or char == '?':
            sentences += 1
    return (sentences)


def check_grade(grade):
    if grade < 1:
        print("Before Grade 1")
    elif grade > 15:
        print("Grade 16+")


main()