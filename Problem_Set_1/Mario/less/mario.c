// Recreate a right-aligned pyramid of blocks from mario in C
#include <cs50.h>
#include <stdio.h>

// Important functions prototypes
int get_height(string prompt);
void print_pyramid(int n);

int main(void)
{
    int height = get_height("Height: ");
    print_pyramid(height);
}

// Get the right number between 1 and 8 inclusive
int get_height(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while (n < 1 || n > 8);
    return n;
}

// Print a right-aligned pyramid
void print_pyramid(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
