#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text)
{
    int len_of_str = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
            len_of_str++;
    }

    return len_of_str;
}

int count_words(string text)
{
    int num_of_words = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]) || text[i] == '.' || text[i] == '!' || text[i] == '?' || text[i] == '\"' || text[i] == ';' || text[i] == ',')
        {
            if(isalpha(text[i + 1]))
                num_of_words++;
            else if((i+1) == strlen(text))
                num_of_words++;
        }
        else if(text[i] == '\'' && (i+1) == strlen(text))
        {
            if(text[i+1] != 's' && isalpha(text[i + 1]))
                num_of_words++;
        }
    }
    return num_of_words;
}

int count_sent(string text)
{
    int num_of_sent = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            num_of_sent++;
    }

    return num_of_sent;
}

int main(void)
{
    string s = get_string("Text: ");

    int num_of_letters = count_letters(s);
    int num_of_words = count_words(s);
    int num_of_sent = count_sent(s);
    float L = (100 * (float)num_of_letters) / (float)num_of_words;
    float S = (100 * (float)num_of_sent) / (float)num_of_words;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    printf("%i\n", num_of_words);

    if(index < 1)
        printf("Before Grade 1\n");

    else if(index > 16)
        printf("Grade 16+\n");

    else
        printf("Grade %i\n", index);
}


