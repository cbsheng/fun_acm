#include <stdio.h>

int main(int argc, char *argv[])
{
    int    n, m;
    int    i;
    int    a[41] = {0, 1};
    scanf("%d", &n);

    while (n--)
    {
        scanf("%d", &m);
        for (i=2; i <= m; i++) {
            a[i] = a[i-1] + a[i-2];
        }
        printf("%d\n", a[m]);
    }
    return    0;
}