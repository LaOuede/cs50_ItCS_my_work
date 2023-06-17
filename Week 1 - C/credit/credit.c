#include <cs50.h>
#include <stdio.h>

long num_len(long nb)
{
    long i;

    i = 1;
    while (nb > 9)
    {
        nb = nb / 10;
        i++;
    }
    return (i);
}

long checkVISA(long x)
{
    do
    {
        x = x / 10;
    }
    while (x > 5);
    if (x % 10 == 4)
    {
        return (1);
    }
    return (0);
}

long checkMASTERCARD(long x)
{
    do
    {
        x = x / 10;
    }
    while (x > 56);
    if (50 < x && x < 56)
    {
        return (1);
    }
    return (0);
}


long checkAMEX(long x)
{
    do
    {
        x = x / 10;
    }
    while (x > 38);
    if (x == 34 || x == 37)
    {
        return (1);
    }
    return (0);
}

int main(void)
{
    long x;
    do
    {
        string number = "What's the number of your credit card?";
        printf("%s\n", number);
        x = get_long("Number: ");
    }
    while (0 > x);
    long    l = num_len(x);
    long    z = x;
    long    mult_add = 0;
    long    total_mult_add = 0;
    long    add = 0;
    long    add_total = 0;
    long    total = 0;
    if (l == 13 || l == 15 || l == 16)
    {
        while (z > 0)
        {
            add = z % 10;
            add_total += add;
            z = z / 10;
            mult_add = (z % 10) * 2;
            if (mult_add >= 10)
            {
                total_mult_add = total_mult_add + ((mult_add / 10) + (mult_add % 10));
            }
            else
            {
                total_mult_add += mult_add;
            }
            z = z / 10;
        }
        total = add_total + total_mult_add;
        if (total % 10 == 0)
        {
            if ((l == 13 || l == 16) && (checkVISA(x) == 1))
            {
                printf("%s\n", "VISA");
            }
            else if ((l == 16) && (checkMASTERCARD(x) == 1))
            {
                printf("%s\n", "MASTERCARD");
            }
            else if ((l == 15) && (checkAMEX(x) == 1))
            {
                printf("%s\n", "AMEX");
            }
            else
            {
                printf("%s\n", "INVALID");
            }
        }
        else
        {
            printf("%s\n", "INVALID");
        }
    }
    else
    {
        printf("%s\n", "INVALID");
    }
    return (0);
}

/*
Checksum :
    - multiply every other digit by 2, starting with second-to-last digit
    - Add those products' digit together
    - Add the sum to the sum of the digits that weren't multiplied by 2
    - If the total's last digit is 0, number is valid!

Cards :
American Express
    15 digits
    starts with 34 or 37
MasterCard
    16 digits
    starts with 51, 52, 53, 54 or 55
Visa
    13 or 16 digits
    starts with 4

TO DO :
    - Prompt for imput
    - Calculate checksum
    - Check for card lenght and starting digits
    - Print AMEX\n, MASTERCARD\n, VISA\n or INVALID\n
*/