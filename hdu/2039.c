#include <stdio.h>

int main(int argc, char *argv[])
{
    int    n;
    double    a[3];
    scanf("%d%*c", &n);
    while (n--)
    {
        scanf("%lf %lf %lf%*c", a, a+1, a+2);
        if (a[0]+a[1]>a[2] && a[1]+a[2]>a[0] && a[2]+a[0]>a[1] ? puts("YES") : puts("NO") );
    }
    return    0;
}