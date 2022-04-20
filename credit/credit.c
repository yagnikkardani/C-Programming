#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long Number = 0;
    int length;
    int valid1 = 0;
    int valid2 = 0;
    int digitCheck = 0;
    bool isValid = false;

    do
    {
        Number = get_long("Number: ");
        length = floor(log10(Number)) + 1;
    }
    while (length == 0);

    if(length == 13 || length == 15 || length ==16)
    {
        for (int i = 1; i <= length; i++)
        {
            if (i % 2 == 0)
            {
                int part1 = 2 * (Number % 10);
                int part2 = 0;

                if (log10(part1) + 1 > 1)
                {
                    do
                    {
                    part2 = part2 + (part1 % 10);
                    part1 = part1 / 10;
                    }
                    while(log10(part1) + 1 > 0);
                }
                else
                    part2 = part1;

                valid1 = valid1 + part2;
            }

            else
            {
                valid2 = valid2 + (Number % 10);
            }

            if ((floor(log10(Number)) + 1) == 2)
            {
                digitCheck = digitCheck + (Number % 10);
            }
            else if((floor(log10(Number)) + 1) == 1)
            {
                digitCheck = digitCheck + (Number * 10);
            }
            Number = Number / 10;
        }
        valid1 = valid1 + valid2;

        if(valid1 % 10 == 0)
        {
            isValid = true;
        }
    }

    if(isValid == true)
    {
        if (digitCheck == 34 || digitCheck == 37)
            printf("AMEX\n");
        else if (digitCheck >= 51 && digitCheck <= 55)
            printf("MASTERCARD\n");
        else if (digitCheck / 10 == 4)
            printf("VISA\n");
        else
        printf("INVALID\n");
    }
    else
        printf("INVALID\n");
}