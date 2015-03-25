#include <stdio.h>

int main()
{
    int    n, i;
    int    a[55] = {1,2,3,4,6};
    for (i = 5; i < 55; i++)
    {
        a[i] = a[i-1] + a[i-3];    
    }
    while (scanf("%d", &n), n)
    {
        printf("%d\n", a[n-1]);
    }
    return    0;
}