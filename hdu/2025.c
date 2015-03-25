#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char    str[105];
    int     i, temp;
    while (scanf("%s", str) != EOF)
    {
        temp = 0;
        for (i = 0; i < strlen(str); i++)
        {
            if (temp < (int)str[i])    
            {
                temp = str[i];
            }
        }
        for (i = 0; i < strlen(str); i++)
        {
            temp == str[i] ? printf("%c%s", str[i], "(max)") : printf("%c", str[i]);
        }
        memset(str, 0, sizeof(str));
        printf("\n");
    }
    return    0;
}