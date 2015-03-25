#include <stdio.h>
#include <string.h>

int main()
{
    int    n;
    int    j;
    int    a, e, i, o, u;
    scanf("%d%*c", &n);
    while (n--)
    {
        a=e=i=o=u=0;
        while ((j = getchar()) != '\n')
        {
            switch (j)
            {
            case 'a':
                a++;
                break;
            case 'e':
                e++;
                break;
            case 'i':
                i++;
                break;
            case 'o':
                o++;
                break;
            case 'u':
                u++;
                break;
            }
        }
        printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n", a, e, i,o, u);
        if (n != 0)
            printf("\n");
    }

    return    0;
}