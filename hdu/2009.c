#include <stdio.h>
#include <math.h>

int main()
{
    int    n, m;
    int    i;
    double result;
    double front;

    while (scanf("%d %d", &n, &m) != EOF)
    {
        result = n;
        front = n;
        for (i = 1; i < m; i++)
        {
            result += sqrt(front);
            front = sqrt(front);
        }
        printf("%.2f\n", result);
    }
    return    0;
}