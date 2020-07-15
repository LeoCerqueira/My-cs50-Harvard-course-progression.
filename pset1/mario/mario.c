#include<stdio.h>
#include<cs50.h>

int main(void)



         

{
    int n;
    do
    {
        n = get_int("Positive Number (btween 1 and 8):");
    }
    while (n < 1 || n > 8);

    for (int i = 0 ; i < n ; i++)
    {
        for (int j = i + 1 ; j < n ; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i ; k++)
        {
            printf("#");
        }
        for (int l = 0; l < 2; l++)
        {
            printf(" ");
        }
        for (int o = 0; o <= i; o++)
        {
            printf("#");
        }
        printf("\n");
    }
}