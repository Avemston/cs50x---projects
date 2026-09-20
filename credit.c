#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask user for the number
    long card_number = get_long("Number: ");

    // Count the digits
    long temp_number = card_number;
    long digit_count = 0;
    while (temp_number > 0)
    {
        temp_number = temp_number / 10;
        digit_count++;
    }

    if (digit_count != 13 && digit_count != 15 && digit_count != 16)
    {
        printf("INVALID\n");
    }

    // What is the working number
    int digit = 0;
    int odds = 0;
    int evens = 0;
    int double_digit = 0;
    long working_number = card_number;
    while (working_number > 0)
    {
        digit = working_number % 10;
        odds = odds + digit;

        working_number = working_number / 10;

        digit = working_number % 10;
        double_digit = digit * 2;
        evens = evens + double_digit % 10 + double_digit / 10;

        working_number = working_number / 10;
    }

    int test_number = odds + evens;

    if (test_number % 10 == 0)
    {
        long final_card = card_number;
        while (final_card > 99)
        {
            final_card = final_card / 10;
        }

        if (digit_count == 15 && (final_card == 34 || final_card == 37))
        {
            printf("AMEX\n");
        }
        else if ((digit_count == 16 || digit_count == 13) && final_card >= 40 && final_card <= 49)
        {
            printf("VISA\n");
        }
        else if (digit_count == 16 && (final_card == 51 || final_card == 52 || final_card == 53 ||
                                       final_card == 54 || final_card == 55))
        {
            printf("MASTERCARD\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
