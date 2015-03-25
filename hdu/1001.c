#include <stdio.h>

int main(int argc, char *argv[])
{
    int   n, sum;
    int   i;
    while (scanf("%d", &n) != EOF)
    {
        sum = 0;
        for (i = 1; i <= n; i++)
        {
            sum += i;
        }
        printf("%d\n\n", sum);
    }
    return    0;
}