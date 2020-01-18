#include <cs50.h>
#include <stdio.h>
#include <math.h>

//Important functions prototypes
int length(long n);
int checksum(long n);
void validate_card_head(long n);
void validate_card(long n);

int main(void)
{
    long number = get_long("Number: ");
    validate_card(number);
}

//Return length of a number
int length(long n)
{
    int count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

//Return the checksum of the credit card
int checksum(long n)
{
    long n1 = n, n2 = n;
    int sum_n1_s2l = 0, sum_n2_l = 0, card_length = length(n);
    
    // Make the sum of all digit in an even position
    for (int i = 1; i <= card_length; i++)
    {
        if (i % 2 == 0)
        {
            int s2l_mul = (n1 % 10) * 2;
            int s2l_length = length(s2l_mul);
            if (s2l_length > 1)
            {
                int s2l_sum = 0;
                for (int j = 1; j <= s2l_length; j++)
                {
                    s2l_sum += (s2l_mul % 10);
                    s2l_mul /= 10;
                }
                sum_n1_s2l += s2l_sum;
            }
            else
            {
                sum_n1_s2l += s2l_mul;
            }
        }
        n1 /= 10;
    }
    
    // Make the sum of all digit in an odd position
    for (int i = 1; i <= card_length; i++)
    {
        if (i % 2 == 1)
        {
            sum_n2_l += (n2 % 10);
        }
        n2 /= 10;
    }
    return sum_n1_s2l + sum_n2_l;
}

//Verify a credit card's two first numbers or first number
void validate_card_head(long n)
{
    int card_length = length(n);
    int two_n = 0;
    for (int i = 1; i <= card_length - 1; i++)
    {
        n /= 10;
        if (i == card_length - 2)
        {
            two_n = n;
        }
    }
    if (two_n == 34 || two_n == 37)
    {
        printf("AMEX\n");
    }
    else if (two_n == 51 || two_n == 52 || two_n == 53 || two_n == 54 || two_n == 55)
    {
        printf("MASTERCARD\n");
    }
    else if (n == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

//Validate a credit card
void validate_card(long n)
{
    int card_length = length(n);
    if (card_length != 15 && card_length != 16 && card_length != 13)
    {
        printf("INVALID\n");
    }
    else 
    {
        int check = checksum(n);
        if (check % 10 != 0)
        {
            printf("INVALID\n");
        }
        else
        {
            validate_card_head(n);
        }
    }
}
