#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    int key = 0;
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        key = atoi(argv[1]);
        string plaintext = get_string("Plaintext: ");
        string ciphertext = plaintext;

        for (int i = 0; i < strlen(plaintext); i++)
        {
            char cipher = rotate (plaintext[i], key);
            ciphertext[i] = cipher;
        }
        printf("ciphertext: %s\n", ciphertext);

        return 0;
    }
}

bool only_digits(string s)
{
    bool flag = true;
    for(int i = 0; i < strlen(s); i++)
    {
        if(!isdigit(s[i]))
            flag = false;
    }
    return flag;
}

char rotate(char c, int n)
{
    char ciph;
    if(isalpha(c))
    {
        int a = (int)c + n;

        if (a >= 91 && a <= 96)
        {
            a = 65 + (a - 91);
            printf("\nVALUE: %i\n", a);
        }

        else if (a > 122)
        {
            do{
                a = 97 + (a - 123);
            }
            while(a > 122);
        }

        ciph = (char)(a);
    }

    else
        ciph = c;

    return ciph;
}