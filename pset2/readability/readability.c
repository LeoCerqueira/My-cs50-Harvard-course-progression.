#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{

    string text = get_string("Text: ");
    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0, n = strlen(text); i <= n; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters = letters + 1;
        }
    }

    for (int q = 0, w = strlen(text); q <= w; q++)
    {
        if (text[q] == ' ' && text[q + 1] != ' ')
        {
            words = words + 1;
        }
    }

    for (int a = 0, z = strlen(text); a <= z; a++)
    {
        if (text[a] == '.' || text[a] == '!' || text[a] == '?')
        {
            sentences = sentences + 1;
        }
    }

    float L = (letters * 100) / words;
    float S = (sentences * 100) / words;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);


    // printf("%i letter(s)\n", letters);
    // printf("%i word(s)\n", words);
    // printf("%i sentence(s)\n", sentences);
    // printf("%i\n", grade);

    if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }

    if (grade > 1 && grade < 16)
    {
        printf("Grade %i\n", grade);
    }

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }

}
