#include<stdio.h>
#include<cs50.h>

int main(void)
{

    long crd = get_long("Number:\n");

    int q = (crd / 10) % 10;
    int w = (crd / 1000) % 10;
    int e = (crd / 100000) % 10;
    int r = (crd / 10000000) % 10;
    int t = (crd / 1000000000) % 10;
    int y = (crd / 100000000000) % 10;
    int u = (crd / 10000000000000) % 10;
    int i = (crd / 1000000000000000) % 10;

    int a = q * 2;
    int s = w * 2;
    int d = e * 2;
    int f = r * 2;
    int g = t * 2;
    int h = y * 2;
    int j = u * 2;
    int k = i * 2;

    int q1 = a / 10;
    int q2 = a % 10;
    int w1 = s / 10;
    int w2 = s % 10;
    int e1 = d / 10;
    int e2 = d % 10;
    int r1 = f / 10;
    int r2 = f % 10;
    int t1 = g / 10;
    int t2 = g % 10;
    int y1 = h / 10;
    int y2 = h % 10;
    int u1 = j / 10;
    int u2 = j % 10;
    int i1 = k / 10;
    int i2 = k % 10;

    int sum1 = q1 + q2 + w1 + w2 + e1 + e2 + r1 + r2 + t1 + t2 + y1 + y2 + u1 + u2 + i1 + i2;

    int z = crd % 10;
    int x = (crd / 100) % 10;
    int c = (crd / 10000) % 10;
    int v = (crd / 1000000) % 10;
    int b = (crd / 100000000) % 10;
    int n = (crd / 10000000000) % 10;
    int m = (crd / 1000000000000) % 10;
    int l = (crd / 100000000000000) % 10;

    int sum2 = sum1 + z + x + c + v + b + n + m + l;


    if (sum2 % 10 == 0)

    {
        if (i == 4)

        {
            printf("VISA\n");
            return (0);
        }

        if (i == 5 && (l == 4 || l == 7 || l == 5 || l == 3 || l == 2 || l == 1))

        {
            printf("MASTERCARD\n");
            return (0);
        }

        if (i == 0 && l == 3 && (u == 4 || u == 7))

        {

            printf("AMEX\n");
            return (0);

        }

        if (i == 0 && l == 0 && m == 0 && u == 0)

        {

            printf("INVALID\n");
            return (0);

        }

        if (i == 0 && l == 0)

        {

            printf("VISA\n");
            return (0);

        }
        else
        {
            printf("INVALID\n");
            return (0);
        }

    }

    if (sum2 % 10 > 0)

    {

        printf("INVALID\n");
        return (0);

    }

}