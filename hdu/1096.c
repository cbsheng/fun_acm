#include <stdio.h>

int main(int argc, char *argv[])
{
    int    n, m, j, sum;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &m);
        sum = 0;
        while (m--)
        {
            scanf("%d", &j);
            sum += j;
        }
        printf(n ? "%d\n\n" : "%d\n", sum);
    }
    return    0;
}