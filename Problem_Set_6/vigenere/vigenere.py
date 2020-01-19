# Implement the vigenere cipher


from cs50 import *


def main():
    if (len(sys.argv) != 2):
        print("Usage: python vigenere.py k")
        sys.exit(1)
    else:
        if (not sys.argv[1].isalpha()):
            print("Usage: python vigenere.py k")
            sys.exit(1)
        else:
            plaintext = get_string("plaintext: ")
            keyC = correspond(sys.argv[1])
            ciphertext = encipher(plaintext, keyC)
            print(f"ciphertext: {ciphertext}")


def correspond(keyword):
    keyC = []
    for i in keyword:
        if i.isupper():
            keyC.append(ord(i) - 65)
        elif i.islower():
            keyC.append(ord(i) - 97)
    return keyC


# Enciphering the given string


def encipher(plaintext, keyC):
    ciphertext = ""

    j = 0
    for i in range(len(plaintext)):
        if (plaintext[i].isalpha()):
            if (plaintext[i].islower()):
                ciphertext += chr((((ord(plaintext[i]) - 97) + keyC[(j % len(keyC))]) % 26) + 97)
            elif (plaintext[i].isupper()):
                ciphertext += chr((((ord(plaintext[i]) - 65) + keyC[(j % len(keyC))]) % 26) + 65)
            j += 1
        else:
            ciphertext += plaintext[i]

    return ciphertext


if __name__ == "__main__":
    main()
