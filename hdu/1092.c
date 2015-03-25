#include <stdio.h>

int main(int argc, char *argv[])
{
    int     n, j, sum;
    while (scanf("%d", &n), n)
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