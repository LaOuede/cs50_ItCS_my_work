#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int BITS_IN_BYTE = 8;

// void print_bulb(int bit);
void bin(unsigned n);

int main(void)
{
    // TODO
    string s;
    int n;
    int i = 0;

    s = get_string("Message: ");
    while (s[i])
    {
        n = s[i];
        bin(n);
        printf("\n");
        i++;
    }
}

// iterative method
void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << (BITS_IN_BYTE - 1); i > 0; i = i >> 1)
    // i = 1 << (BITS_IN_BYTE - 1) veut dire qu'on prend le premier byte uniquement
    // i = i >> 1 est l'équivalent de i = i / 2 (cf. shift operator wikipedia)
        if (n & i)
        {
            printf("\U0001F7E1");
        }
        else
        {
            printf("\U000026AB");
        }
        // peut simplement s'écrire :
        // (n & i) ? printf("\U0001F7E1") : printf("\U000026AB");
        // n & i veut dire (exemple n=72 => 01001000) 01001000 & 0 => 0 (vu que i = premier byte)
}

// // recursive method
// void bin(unsigned n)
// {
//     /* step 1 */
//     if (n > 1)
//         bin(n / 2);

//     /* step 2 */
//     printf("%d", n % 2);
// }

// void print_bulb(int bit)
// {
//     if (bit == 0)
//     {
//         // Dark emoji
//         printf("\U000026AB");
//     }
//     else if (bit == 1)
//     {
//         // Light emoji
//         printf("\U0001F7E1");
//     }
// }
