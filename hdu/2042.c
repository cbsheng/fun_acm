#include <stdio.h>

int main(int argc, char *argv[])
{
    int    n, i, j, sum;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &j);
        sum = 3;
        for (i = 1; i <= j; i++) {
            sum = (sum - 1) * 2;
        }
        printf("%d\n", sum);
        
    }
    return    0;
}