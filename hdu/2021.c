#include <stdio.h>

int main()
{
    int    n, i, j, sum;
    int    m[6] = {100, 50, 10, 5, 2, 1};
    while (scanf("%d", &n), n)
    {
        sum = 0;
        while (n--)
        {
            scanf("%d", &j);
            for (i = 0; j != 0; i++)
            {
                while (j >= m[i])
                {
                    j -= m[i];
                    sum++;
                }
            }
        }
        printf("%d\n", sum);
    }
    return    0;
}