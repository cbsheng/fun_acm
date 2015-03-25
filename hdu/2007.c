#include <stdio.h>
#include <math.h>

#define  odd(m) ( (m&1) ? 1 : 0 )

int main()
{
    int    m, n;
    int    i;
    int    re1, re2;
    while (scanf("%d %d", &m, &n) != EOF)
    {
        re1 = 0;
        re2 = 0;
        if (m > n) 
        {
            int temp = m;
            m = n;
            n = temp;
        }
        for (i = m; i <= n; i++)
        {
            if (odd(i))
            {
                re1 += i*i*i;
            }            
            else
            {
                re2 += i*i;
            }
        }
        printf("%d %d\n", re2, re1);
    }
    return    0;
}