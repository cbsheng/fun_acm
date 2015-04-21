//Url:http://uva.onlinejudge.org/external/4/424.pdf

#include <cstdio>
#include <cstring>

char  l[120];
int   sum[120];

int main()
{
    freopen("testdata/424.in", "r", stdin);
    int   n=0;
    int   c, tmp;
    while (scanf("%s", l))
    {
        //printf("%s\n", l);
        if (strlen(l) == 1 && l[0] == '0')
            break;
        c = 0;
        int i=0;
        int j=strlen(l)-1;
        int a;
        for (; i<120; ++i)
        {
            if (j>=0)
                a = l[j--] - '0';
            else
                a = 0;
            tmp = sum[i] + a + c;
            c = tmp / 10;
            sum[i] = tmp % 10;
        }
    }
    int  pos=119;
    for (; pos>=0; --pos)
        if (sum[pos] != 0)
            break;
    for (; pos >=0; --pos)
        printf("%d", sum[pos]);
    puts("");
    return 0;
}
