// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

string replace(string str);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./novowels word / Try again :)\n");
        return (1);
    }
    replace(argv[1]);
    return (0);
}

string replace(string str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == 'a')
        {
            str[i] = '6';
        }
        if (str[i] == 'e')
        {
            str[i] = '3';
        }
        if (str[i] == 'i')
        {
            str[i] = '1';
        }
        if (str[i] == 'o')
        {
            str[i] = '0';
        }
        i++;
    }
    printf("%s\n", str);
    return (0);
}
