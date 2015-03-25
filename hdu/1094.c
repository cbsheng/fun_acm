#include <stdio.h>

int main(int argc, char *argv[])
{
    int     m;
    int     n, j, sum;
    while (scanf("%d", &n) != EOF)
    {
        sum = 0;
        while (n--)
        {
            scanf("%d", &j);
            sum += j;
        }
        printf("%d\n", sum);
    }
    return    0;
}