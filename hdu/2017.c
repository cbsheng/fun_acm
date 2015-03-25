#include <stdio.h>
#include <ctype.h>


int main()
{
    int    n, sum;
    char   c;
    scanf("%d%*c", &n);
    while (n--)
    {
        sum = 0;
        for (sum = 0; (c = getchar()) != '\n';)
        {
            if (isdigit(c))
                sum++;
        }
        printf("%d\n", sum);
    }
    return    0;
}