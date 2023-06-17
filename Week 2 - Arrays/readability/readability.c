#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    string s;
    s = get_string("Text: ");
    int letters = count_letters(s);
    int words = count_words(s);
    int sentences = count_sentences(s);
    float L = (float)letters / (float)words * 100;
    float S = (float)sentences / (float)words * 100;
    float grade = (0.0588 * L) - (0.296 * S) - 15.8;
    if ((int) round(grade) < 1)
    {
        printf("Before Grade 1\n");
    }
    else if ((int) round(grade) > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(grade));
    }
    return (0);
}

int count_letters(string s)
{
    int i = 0;
    int letters = 0;

    while (s[i] != '\0')
    {
        if (isalpha(s[i]) != 0)
        {
            letters += 1;
        }
        i++;
    }
    return (letters);
}

int count_words(string s)
{
    int i = 0;
    int words = 1;

    while (s[i] != '\0')
    {
        if (s[i] == ' ')
        {
            words += 1;
        }
        i++;
    }
    return (words);
}

int count_sentences(string s)
{
    int i = 0;
    int sentences = 0;

    while (s[i] != '\0')
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences += 1;
        }
        i++;
    }
    return (sentences);
}
