#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    int     n;
    int     i, sign;
    char    str[100];

    scanf("%d%*c", &n);
    while (n--)
    {
        sign = 1;
        gets(str);
        for (i = 0; i < strlen(str) / 2; i++) {
            if (str[i] != str[strlen(str) - 1 - i]) {
                sign = 0;
                break;
            }
        }
        sign ? puts("yes") : puts("no");
        
    }
    return     0;
}