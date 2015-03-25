#include <stdio.h>
#include <math.h>

int main()
{
    int    n;
    int    i;
    int    result;
    int    y;
    while (scanf("%d", &n) != EOF)
    {
        y = 1;
        for (i = 1; i < n; i++)
        {
            result = 2 * ( y + 1 );
            y = result;
        }
        printf("%d\n", result);
    }
    return    0;
}