#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x;

    do
    {
        string height = "What's the height of the pyramid?";
        printf("%s\n", height);
        x = get_int("Positive integer: ");
    }
    while (8 < x || x < 1);

    for (int i = x; i > 0; i--) //i = x = height
    {
        for (int j = 1; j < i; j++) //decrease i to obtain a pyramid and not a square
//j = 1 because there is no space on the bottom line
        {
            printf(" "); //print spaces before bricks
        }
        for (int k = i; k <= x; k++) //opposite of the other loop
        {
            printf("#"); //print bricks
        }
        printf("  "); //print spaces;
        for (int j = i; j <= x; j++)
        {
            printf("#"); //print bricks
        }
        printf("\n"); //print new line
    }
}