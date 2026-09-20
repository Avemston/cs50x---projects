#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

bool valid_key(string key);
// Receive user's key
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            return 1;
        }
    }

    string key = argv[1];

    if (!valid_key(key))
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }

    // Receive user's message
    string text = get_string("plaintext: ");

    printf("ciphertext:");

    for (int i = 0; text[i]; i++)
    {
        if (isupper(text[i]))
        {
            int position = text[i] - 'A';
            printf("%c", toupper(key[position]));
        }

        else if (islower(text[i]))
        {
            int position = text[i] - 'a';
            printf("%c", tolower(key[position]));
        }

        else
            printf("%c", text[i]);
    }
    printf("\n");
}
// Output the encrypted message

bool valid_key(string key)
{
    for (int i = 0; key[i] != '\0'; i++)
    {
        for (int j = i + 1; key[j] != '\0'; j++)
        {
            if (key[i] == key[j])
            {
                printf("Do not use duplicate letters.\n");
                return false;
            }
            if (isupper(key[i]) == islower(key[j]))
            {
                printf("Do not use duplicate letters.\n");
                return false;
            }
        }
    }
    return true;
}
