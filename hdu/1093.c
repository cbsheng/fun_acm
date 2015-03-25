#include <stdio.h>

int main(int argc, char *argv[])
{
    int     m;
    int     n, j, sum;
    scanf("%d", &m);
    while (m--)
    {
        scanf("%d", &n);
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