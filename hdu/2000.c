#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return  *(char*)a>*(char*)b ? 1 : 0;
}
int main()
{
    char    input[3];
    while (scanf("%s", input) != EOF)
    {
        qsort(input, sizeof(input), 1,cmp);
        printf("%c %c %c\n", input[0], input[1], input[2]);
    }
}