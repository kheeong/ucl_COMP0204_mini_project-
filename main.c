#include <stdio.h>
#include <string.h>

char one_to_ten[10][10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
char eleven_to_nineteen[9][11] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char twenty_to_ninety[8][10] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
char hundred[] = "hundred";
char thousand[] = "thousand";
char million[] = "million";

int char_to_int(char c)
{
    return c - '0';
}

int print_word_from_3_digit(char temp[4])
{
    if (char_to_int(temp[0]) != 0)
    {
        printf("%s %s", one_to_ten[char_to_int(temp[0]) - 1], hundred);
    }
    if (char_to_int(temp[1]) != 0)
    {
        if (char_to_int(temp[0]) != 0)
        {
            printf(" and ");
        }
        if (char_to_int(temp[1]) == 1 && char_to_int(temp[2]) != 0)
        {
            printf("%s", eleven_to_nineteen[char_to_int(temp[2]) -1]);
        }else if (char_to_int(temp[1]) == 1 && char_to_int(temp[2]) == 0)
        {
            printf("ten");
        }
        else
        {
            printf("%s", twenty_to_ninety[char_to_int(temp[1]) - 2]);
            if (char_to_int(temp[2]) != 0 && char_to_int(temp[1]) == 0)
            {
                printf(" and %s", one_to_ten[char_to_int(temp[2]) - 1]);
            }
            else if (char_to_int(temp[2]) != 0)
            {
                printf("%s", one_to_ten[char_to_int(temp[2]) - 1]);
            }
        }
    }
    else
    {
        if (char_to_int(temp[2]) != 0 && char_to_int(temp[1]) == 0)
        {
            printf(" and %s", one_to_ten[char_to_int(temp[2]) - 1]);
        }
        else if (char_to_int(temp[2]) != 0 && char_to_int(temp[0]) == 0 && char_to_int(temp[1]) == 0)
        {
            printf("%s", one_to_ten[char_to_int(temp[2]) - 1]);
        }
    }
}

int main()
{
    printf("Hello World\n");
    int min = 1;
    long max = 1000000;
    long input;
    scanf("%d", &input);
    while (1)
    {
        if (input < min || input > max)
        {
            printf("Invalid input\n");
            scanf("%d", &input);
        }
        else
        {
            break;
        }
    }

    char input_str[7];
    sprintf(input_str, "%07d", input);
    if (input_str[0] != '0')
    {
        printf("%s %s", one_to_ten[char_to_int(input_str[0]) - 1], million);
    }
    char temp[4];
    for (int i = 1; i < 4; i++)
    {
        temp[i - 1] = input_str[i];
    }
    print_word_from_3_digit(temp);
    if (temp[0] != '0' || temp[1] != '0' || temp[2] != '0')
    {
        printf(" %s ", thousand);
    }
    for (int i = 4; i < 7; i++)
    {
        temp[i - 4] = input_str[i];
    }
    print_word_from_3_digit(temp);
    printf("\n");
    return 0;
}