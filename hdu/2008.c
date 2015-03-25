#include <stdio.h>
int main()
{
    int    n;
    int    i;
    double j;
    int    pos, neg, zero;
    while (scanf("%d", &n) != EOF)
    {
        neg = 0;
        pos = 0;
        zero = 0;
        if (n == 0)
            return    0;
        for (i = 0; i < n; i++)
        {
            scanf("%lf", &j);
            if(j*1 == 0)
            {zero++;continue;}
            if (j*1 > 0) 
            {pos++;continue;}
            neg++;
            
        }
        printf("%d %d %d\n", neg, zero, pos);
    }
    return    0;
}