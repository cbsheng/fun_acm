#include <stdio.h>

int main()
{
    double  j, n, max, min, result;
    int    i;
    while (scanf("%lf", &n) != EOF)
    {
        max = 0.0;
        min = 100.0;
        result = 0.0;
        for (i = 0; i < (int)n; i++)
        {
            scanf("%lf", &j);    
            if (max < j) max = j;
            if (min > j) min = j;
            result += j;
        }
        printf("%.2f\n", (result-max-min)/(n-2));
    }
    return    0;
}