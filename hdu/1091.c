#include <stdio.h>

int main(int argc, char *argv[])
{
    long    a, b;
    while (scanf("%d %d", &a, &b), a || b)
    {
        printf("%d\n", a+b);
    }
    return    0;
}