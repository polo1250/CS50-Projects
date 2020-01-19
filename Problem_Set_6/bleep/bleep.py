from cs50 import get_string
import sys


def main():
    if (len(sys.argv) != 2):
        print("Usage: python bleep.py dictionary")
        sys.exit(1)

    bannedWords = readWords(sys.argv[1])

    userText = get_string("What message would you like to censor?\n")
    censoredText = censorer(userText, bannedWords)
    print(censoredText)


def readWords(filename):
    # Open and read the file and stores its words

    bannedTxt = open(filename, "r")
    bannedWords = set()
    for w in bannedTxt:  # Read through the file and stores the words in the set
        bannedWords.add(w[:-1])
    bannedTxt.close()
    return bannedWords


def getCensor(word):
    # Return a star-filled word of the same length of the censored word
    return "*" * len(word)


def censorer(text, bannedW):
    # Return a censored text
    text = text.split()
    censorText = []
    for w in text:
        if w.lower() in bannedW:
            censorText.append(getCensor(w))
        else:
            censorText.append(w)
    return " ".join(censorText)


if __name__ == "__main__":
    main()

