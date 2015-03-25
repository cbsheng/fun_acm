#include <stdio.h>
int main(int argc, char *argv[])
{
    int     a, b;
    int     i;
    int     re;
    
    while (scanf("%d %d%*c", &a, &b), a | b)
    {
        re = a;
        for (i = 0; i < b-1; i++) {
            re = (a*re) % 1000;
        }
        printf("%d\n", re);    
    }
    return    0;
}