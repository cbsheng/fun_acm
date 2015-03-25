#include <stdio.h>
#include <math.h>

#define   odd(n) (n%2)==0 ? 0 : 1

int main()
{
    int    i;
    int    n, k, result = 1;
    while (scanf("%d", &n) != EOF)
    {
        result = 1;
        for (i = 0; i < n ; i++)
        {
            scanf("%d", &k);    
            if (odd(k))
            {
                result *= k;    
            }
        }
        printf("%d\n", result);
    }
    return    0;
}