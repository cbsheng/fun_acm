#include <stdio.h>
#include <math.h>

int main()
{
    int    m, n;
    int    i, j = 1;
    int    sign=0;
    while (scanf("%d %d", &m, &n) != EOF)
    {
        sign = 0;
        j = 1;
        for (i = m; i <= n; i++)
        {
            if (i == (int)( pow((double)(i/100), 3) + pow((double)(i/10%10), 3) + pow((double)(i%10), 3)) )
            {
                sign = 1;
                if (j)
                {
                    printf("%d", i);
                    j--;
                }
                else
                    printf(" %d", i);
            }
        }
        if (!sign) printf("no");
        printf("\n");
    }
    return    0;
}