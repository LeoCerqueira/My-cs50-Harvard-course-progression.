#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)

{

    float n;
    do
    {

        n = get_float("Change owned:");

    }
    while (n <= 0);

    int cents = round(n * 100);

    int result25 = cents / 25;
    int reminder25 = cents % 25;

    int result10 = reminder25 / 10;
    int reminder10 = reminder25 % 10;

    int result5 = reminder10 / 5;
    int reminder5 = reminder10 % 5;

    int result1 = reminder5 / 1;


    printf("%i\n", result25 + result10 + result5 + result1);

}
