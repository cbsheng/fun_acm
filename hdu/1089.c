#include <stdio.h>

int main(int argc, char *argv[])
{
    long    a, b;
    while (scanf("%d %d", &a, &b) != EOF)
    {
        printf("%d\n", a+b);
    }
    return    0;
}