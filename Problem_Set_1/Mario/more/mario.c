// Recreate adjacent pyramids of blocks from Mario in C
#include <cs50.h>
#include <stdio.h>

// Important functions prototypes
int get_height(string prompt);
void print_pyramids(int n);

int main(void)
{
    int height = get_height("Height: ");
    print_pyramids(height);
}

// Get the correct height from user
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

// Print the block of pyramids
void print_pyramids(int n)
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
        printf("  ");
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
