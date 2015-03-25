#include <stdio.h>
#include <string.h>
#include <math.h>

char    left[1010], right[1010], result[2000];

int main()
{
    int     n, i, j, c=1;
    int     pre, pos_l, pos_r;
    scanf("%d", &n);
    while ( n-- )
    {
        pre = 0;
        pos_l = -1;
        pos_r = -1;
        memset(left, 'e', sizeof(left));
        memset(right, 'e', sizeof(right));
        memset(result, 'e', sizeof(result));
        scanf("%s %s", left, right);
        
        for ( i=1009; pos_l < 0 || pos_r < 0; i-- )
        { 
            if ((left[i] != 'e' && left[i] != '\0') && pos_l == -1)
                pos_l = i;
            if ((right[i] != 'e' && right[i] != '\0') && pos_r == -1)
                pos_r = i;
        }
        j = 1999;
        pre = 0;
        int     a, b;
        while (pos_l >= 0 || pos_r >= 0)
        {
            a = (pos_l < 0) ? 0 : left[pos_l]-'0';
            b = (pos_r < 0) ? 0 : right[pos_r]-'0';

            result[j--] = ((a + b) % 10 + pre)%10 + '0';
            pre = (a + b + pre) / 10;
            if (pos_l >= 0) pos_l--;
            if (pos_r >= 0) pos_r--;
            if (pos_r < 0 && pos_l < 0 && pre > 0)
                result[j] = pre + '0';
        }
        printf("Case %d:\n%s + %s = ", c++, left, right);
        for (i = 0; i<2000; i++)
        {
            if (result[i] != 'e')
                printf("%c", result[i]);
        }
        if (n>0)
        {
            printf("\n\n");
        }
        else
        {
            printf("\n");
        }
    }

    return 0;
    
}