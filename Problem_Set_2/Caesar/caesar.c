//This program implement the caesar cipher
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//Important functions prototypes
string encipher(string plaintext, int key);
int ifalpha(string text);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        if (ifalpha(argv[1]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            int key = atoi(argv[1]);
            string plaintext = get_string("plaintext: ");
            string ciphertext = encipher(plaintext, key);
            printf("ciphertext: %s\n", ciphertext);
        }
    }
    return 0;
}

// check for alphabets 
int ifalpha(string text)
{
    int alphabet = 0; 
    for (int i = 0, n = strlen(text); i < n; i++) 
    {   
        if (isalpha(text[i]) != 0)
        {
            alphabet++;
        }
    } 
    return alphabet;
}

//encipher the string provided by the user
string encipher(string plaintext, int key)
{
    string ciphertext = plaintext;
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
                ciphertext[i] = (((ch - 97) + key) % 26) + 97;
            }
            else if (isupper(ch))
            {
                ciphertext[i] = (((ch - 65) + key) % 26) + 65;
            }
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    return ciphertext;
}
