#include <stdio.h>

#define  an(a1, n) (a1 + (n-1)*2)
#define  sn(a1, n) ((a1+an(a1, n))*n / 2)
int main()
{
    int    n, m;
    int    result;
    int    i, j;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        result = 0;
        i = 2;
        j = 0;
        while (n > 0)
        {
            if (n < m)  
            {
                printf(j++ ? " %d" : "%d", sn(i,n) / n);
                n -= m;
            }
            else
            {
                printf(j++ ? " %d" : "%d", sn(i, m) / m);
                i = an(i, m+1);    
                n -= m;
            }
        }
        printf("\n");
    }
    return    0;
}