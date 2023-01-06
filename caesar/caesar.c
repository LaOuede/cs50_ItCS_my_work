#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int only_digits(string s);
char rotate(char c, int i);

int main(int argc, string argv[])
{
    int i = 0;
    int key;
    string s;
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return (1);
    }
    if (argc == 2)
    {
        if (only_digits(argv[1]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return (1);
        }
    }
    key = atoi(argv[1]);
    s = get_string("plaintext:  ");
    while (s[i])
    {
        s[i] = rotate(s[i], key);
        i++;
    }
    printf("ciphertext: %s\n", s);
}

int only_digits(string s)
{
    int i = 0;
    while (s[i])
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            i++;
        }
        else
        {
            return (0);
        }
    }
    return (1);
}

char rotate(char c, int key)
{
    if (isalpha(c) != 0)
    {
        if (islower(c) != 0)
        {
            c = (c - 'a' + key) % 26 + 'a';
            return (c);
        }
        else if (isupper(c) != 0)
        {
            c = (c - 'A' + key) % 26 + 'A';
            return (c);
        }
    }
    if (isalpha(c) == 0)
    {
        return (c);
    }
    return (0);
}
