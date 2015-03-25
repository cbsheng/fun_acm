#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char    str[110];
    char    *p;
    int     i;
    while (gets(str))
    {
        i = 0;
        p = strtok(str, " ");
        while (p)
        {
            p[0] = toupper(p[0]);
            printf(i++ ? " %c%s" : "%c%s", toupper(p[0]),p+1);
            p = strtok(NULL, " ");
        }
        printf("\n");
    }

    return    0;
}