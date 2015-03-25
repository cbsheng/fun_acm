#include <stdio.h>

int main()
{
    int    n, x;
    int    i, j, sign;
    int    data[100];
    while (scanf("%d %d", &n, &x), n || x)
    {
        i = 0;
        j = 0;
        sign = 1;
        while (n--)
        {
            scanf("%d", &data[i]);
            if (x > data[i])
            {
                printf(j++ ? " %d" : "%d", data[i]);
                i++;
            }
            else
            {
                if (sign)
                {
                    printf(j++ ? " %d" : "%d", x);
                    sign = 0;
                }
                    printf(j++ ? " %d" : "%d", data[i]);
            }
        }    
        printf("\n");
    }
    return    0;
}