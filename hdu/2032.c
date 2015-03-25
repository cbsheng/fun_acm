#include <stdio.h >
#include <string.h>

struct str
{
    int   s[31];
} s={0}, s1={0};

int main ()
{
        int    n;
        int    i, j;
        while (scanf("%d", &n) != EOF)
        {
            memset(&s, 0, sizeof(struct str));
            memset(&s1, 0, sizeof(struct str));
            s.s[1] = 1;
            for (i = 1; i <= n; i++)
            {
                for (j = 0; j < i; j++)
                {
                    printf("%d%c", s.s[j] + s.s[j+1], j != i-1 ? ' ':'\n');    
                    s1.s[j+1] = s.s[j] + s.s[j+1];
                }
                s = s1;
            }
            printf("\n");
        }
   return    0;
}