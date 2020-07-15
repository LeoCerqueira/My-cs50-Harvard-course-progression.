#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

int main(int argc, string arcv[])
{


    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return (1);
    }

    int k = atoi(arcv[1]);

    if (k < 1)
    {
        printf("Usage: ./caesar key\n");
        return (1);
    }
    else
    {
        string plain = get_string("plaintext: ");



        printf("ciphertext: ");

        int k1 = k % 26;

        for (int i = 0, n = strlen(plain); i <= n; i++)
        {


            if (plain[i] >= 'A' && plain[i] <= 'Z')
            {
                if ((plain[i] + k1) >= 'Z')
                {
                    char cipher = plain[i] + k1 - 26;
                    printf("%c", cipher);
                }
                else
                {
                    char cipher = plain[i] + k1;
                    printf("%c", cipher);
                }

            }
            if (plain[i] >= 'a' && plain[i] <= 'z')
            {
                if ((plain[i] + k1) >= 'z')
                {
                    char cipher = plain[i] + k1 - 26;
                    printf("%c", cipher);
                }
                else
                {
                    char cipher = plain[i] + k1;
                    printf("%c", cipher);
                }

            }
            if ((plain[i] >= '!' && plain[i] <= '@') || (plain[i] >= '[' && plain[i] <= '`'))
            {
                printf("%c", plain[i]);
            }
            if (plain[i] == ' ')
            {
                printf("%c", plain[i]);
            }

        }
        printf("\n");
        return (0);

    }


}