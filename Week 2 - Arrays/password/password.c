// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

bool valid(string password);
bool lowercase(string password);
bool uppercase(string password);
bool number(string password);
bool symbol(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password) == true)
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    if ((lowercase(password) == true) && (uppercase(password) == true) && (number(password) == true)
        && (symbol(password) == true))
    {
        return true;
    }
    return false;
}

bool lowercase(string password)
{
    int i = 0;
    while (password[i])
    {
        if (islower(password[i]))
        {
            return true;
        }
        i++;
    }
    return false;
}

bool uppercase(string password)
{
    int i = 0;
    while (password[i])
    {
        if (isupper(password[i]))
        {
            return true;
        }
        i++;
    }
    return false;
}

bool number(string password)
{
    int i = 0;
    while (password[i])
    {
        if (isdigit(password[i]))
        {
            return true;
        }
        i++;
    }
    return false;
}

bool symbol(string password)
{
    int i = 0;
    while (password[i])
    {
        if ((32 <= password[i] & password[i] <= 47) || (58 <= password[i] & password[i] <= 64)
            || (91 <= password[i] & password[i] <= 96) || (122 <= password[i] & password[i] <= 126))
        {
            return true;
        }
        i++;
    }
    return false;
}