#include <stdio.h>

int main(int argc, char *argv[])
{
    int     n;
    long    a, b;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", a+b);
    }
    return    0;
}