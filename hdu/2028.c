#include <stdio.h>

typedef unsigned long UL;

UL gcd(UL a, UL b);
UL lcm(UL a, UL b);

int main(int argc, char *argv[])
{

    int     n;
    UL      i, j;
    while (scanf("%d%*c", &n) != EOF)
    {
        i = 1;
        while (n--)
        {
            scanf("%ld%*c", &j);
            i = lcm(i, j);
        }
        printf("%ld\n", i);
    }

    return    0;
}

UL gcd(UL a, UL b)
{
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

UL lcm(UL a, UL b)
{
    return (a * b) / gcd(a, b);
}
