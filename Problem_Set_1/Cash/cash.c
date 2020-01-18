#include <cs50.h>
#include <stdio.h>
#include <math.h>

//Important functions prototypes
int get_change(string prompt);
int get_coins(int change);

int main(void)
{
    int change = get_change("Change owed: ");
    int coins = get_coins(change);
    printf("%i\n", coins);
}

// This function make sure we get a proper value for the change, and round it
int get_change(string prompt)
{
    float change_float;
    int change;
    do
    {
        change_float = get_float("%s", prompt);
        change = round(change_float * 100);
    }
    while (change < 0);
    return change;
}

// This functions return the proper amount of coins owed
int get_coins(int change)
{
    int coins = 0;
    while (change >= 25)
    {
        change -= 25;
        coins++;
    }
    while (change >= 10)
    {
        change -= 10;
        coins++;
    }
    while (change >= 5)
    {
        change -= 5;
        coins++;
    }
    coins += change;
    return coins;
}
