// Implement the vigenere cipher
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//Important functions prototypes
bool if_all_alpha(string text);
void shift(string keyword, int keywordInts[]);
string encipher(string plaintext, int count, int keywordInts[]);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    else
    {
        if (!if_all_alpha(argv[1]))
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
        else
        {
            int length = strlen(argv[1]), keywordInts[length];
            shift(argv[1], keywordInts);
            string plaintext = get_string("plaintext: ");
            string ciphertext = encipher(plaintext, length, keywordInts);
            printf("ciphertext: %s\n", ciphertext);
        }
    }
    return 0;
}

//check if all the characters in the keyword are alphabets
bool if_all_alpha(string text)
{
    int alphabet = 0, n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            alphabet++;
        }
    }
    return alphabet == n;
}

//convert each character of the keywork to its appropriate integer value
void shift(string keyword, int keywordInts[])
{
    for (int i = 0, n = strlen(keyword); i < n; i++)
    {
        char c = keyword[i];
        if (islower(c))
        {
            keywordInts[i] = c - 'a';
        }
        else if (isupper(c))
        {
            keywordInts[i] = c - 'A';
        }
    }
}

//
string encipher(string plaintext, int count, int keywordInts[])
{
    string ciphertext = plaintext;
    int j = 0;
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]) != 0)
        {
            char ch = plaintext[i];
            // Drag down the character ascii value in the range of 0-26
            // then apply the cipher and get the character back in the right range
            // depending of wether it's an uppercase or lowercase character
            if (islower(ch))
            {
                ciphertext[i] = (((ch - 97) + keywordInts[(j % count)]) % 26) + 97;
            }
            else if (isupper(ch))
            {
                ciphertext[i] = (((ch - 65) + keywordInts[(j % count)]) % 26) + 65;
            }
            j++;
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    return ciphertext;
}
