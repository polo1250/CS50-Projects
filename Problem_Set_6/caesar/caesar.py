# This program implement the caesar cipher


import sys
from cs50 import *

# encipher the string provided by the user


def encipher(plaintext, key):
    ciphertext = ""
    for i in range(len(plaintext)):
        if (plaintext[i].isalpha()):
            ch = plaintext[i]
            # Drag down the character ascii value in the range of 0-26
            # then apply the cipher and get the character back in the right range
            # depending of wether it's an uppercase or lowercase character
            if (ch.islower()):
                ciphertext += chr((((ord(ch) - 97) + key) % 26) + 97)
            elif (ch.isupper()):
                ciphertext += chr((((ord(ch) - 65) + key) % 26) + 65)
        else:
            ciphertext += plaintext[i]
    return ciphertext

# check for alphabets


def ifalpha(text):
    alphabet = 0
    for i in range(len(text)):
        if (text[i].isalpha()):
            alphabet += 1
    return alphabet


def main():
    if (len(sys.argv) != 2):
        print("Usage: ./caesar key")
        sys.exit(1)
    else:
        if (ifalpha(sys.argv[1])):
            print("Usage: python caesar.py k")
        else:
            key = int(sys.argv[1])
            plaintext = get_string("plaintext: ")
            ciphertext = encipher(plaintext, key)
            print(f"ciphertext: {ciphertext}")


if __name__ == "__main__":
    main()

