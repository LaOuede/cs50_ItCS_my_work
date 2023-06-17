#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int ft_strlen(char *str);
int ft_checkalpha(char *str);
int ft_check_rep(char *str);
char substitute(char c, char *str);

int main(int argc, string argv[])
{
    string key = 0;
    int i = 0;
    string s;
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return (1);
    }
    if (argc == 2)
    {
        if (ft_strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return (1);
        }
        if (ft_checkalpha(argv[1]) == 0)
        {
            printf("Usage: key characters are not alphabetics\n");
            return (1);
        }
        if (ft_check_rep(argv[1]) == 0)
        {
            printf("Usage: repetition in key characters\n");
            return (1);
        }
    }
    key = argv[1];
    s = get_string("plaintext:  ");
    while (s[i])
    {
        s[i] = substitute(s[i], key);
        i++;
    }
    printf("ciphertext: %s\n", s);
}

int ft_strlen(char *str)
{
    int len = 0;

    if (!str)
    {
        return (0);
    }
    while (str[len] != '\0')
    {
        len++;
    }
    return (len);
}

int ft_checkalpha(char *str)
{
    int i = 0;

    if (!str)
    {
        return (0);
    }
    while (str[i])
    {
        if (isalpha(str[i]) == 0)
        {
            return (0);
        }
        i++;
    }
    return (1);
}

int ft_check_rep(char *str)
{
    int i = 0;
    int j;

    if (!str)
    {
        return (0);
    }
    while (str[i])
    {
        j = i + 1;
        while (str[j])
        {
            if (str[i] == str[j])
            {
                return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

char substitute(char c, char *str)
{
    int pos = 0;
    if (isalpha(c) != 0)
    {
        if (islower(c) != 0)
        {
            pos = (c - 'a');
            if (islower(str[pos]) != 0)
            {
                c = str[pos];
                return (c);
            }
            if (isupper(str[pos]) != 0)
            {
                c = str[pos] + 32;
                return (c);
            }
        }
        else if (isupper(c) != 0)
        {
            pos = (c - 'A');
            if (islower(str[pos]) != 0)
            {
                c = str[pos] - 32;
                return (c);
            }
            if (isupper(str[pos]) != 0)
            {
                c = str[pos];
                return (c);
            }
        }
    }
    if (isalpha(c) == 0)
    {
        return (c);
    }
    return (0);
}
