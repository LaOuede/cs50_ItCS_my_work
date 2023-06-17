#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("Llamas population at the start: ");
    }
    while (start < 9);

    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("Llamas population at the end: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;

    while (start < end)
    {
        start += (start / 3) - (start / 4);
        years++;
    }
    
    // TODO: Print number of years
    int n = years;
    printf("Years: %i\n", n);
}
