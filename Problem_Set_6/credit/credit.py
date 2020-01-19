from cs50 import *

# Return length of a number


def length(n):
    count = 0
    while (n > 0):
        n //= 10
        count += 1
    return count

# Return the checksum of the credit card


def checksum(n):
    n1 = n
    n2 = n
    sum_n1_s2l = 0
    sum_n2_l = 0
    card_length = length(n)

    # Make the sum of all digit in an even position
    for i in range(1, card_length + 1):
        if (i % 2 == 0):
            s2l_mul = (n1 % 10) * 2
            s2l_length = length(s2l_mul)

            if (s2l_length > 1):
                s2l_sum = 0
                for j in range(1, s2l_length + 1):
                    s2l_sum += (s2l_mul % 10)
                    s2l_mul //= 10
                sum_n1_s2l += s2l_sum
            else:
                sum_n1_s2l += s2l_mul
        n1 //= 10

    # Make the sum of all digit in an odd position
    for i in range(1, card_length + 1):
        if (i % 2 == 1):
            sum_n2_l += (n2 % 10)
        n2 //= 10
    return sum_n1_s2l + sum_n2_l

# Verify a credit card's two first numbers or first number


def validate_card_head(n):
    card_length = length(n)
    two_n = 0
    for i in range(1, card_length):
        n //= 10
        if (i == card_length - 2):
            two_n = n
    if (two_n == 34 or two_n == 37):
        print("AMEX\n")
    elif (two_n == 51 or two_n == 52 or two_n == 53 or two_n == 54 or two_n == 55):
        print("MASTERCARD")
    elif (n == 4):
        print("VISA")
    else:
        print("INVALID")

# Validate a credit card


def validate_card(n):
    card_length = length(n)
    if (card_length != 15 and card_length != 16 and card_length != 13):
        print("INVALID")
    else:
        check = checksum(n)
        if (check % 10 != 0):
            print("INVALID")
        else:
            validate_card_head(n)


def main():
    number = int(get_int("Number: "))
    validate_card(number)


if __name__ == "__main__":
    main()
