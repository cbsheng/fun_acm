//Url:http://uva.onlinejudge.org/external/101/10106.pdf
//
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char  x[300], y[300];
int   sum[700];

void multiply(char mul, int p)
{
    //putchar(mul);
    int  m = mul - '0';
    int  tmp;
    int  xlen = strlen(x) - 1;
    int  a;
    for (int i=xlen, j=p; j<700; --i, ++j)
    {
        if (i>=0)
            a = x[i] - '0';
        else
            a = 0;
        tmp = sum[j] + a * m;
        sum[j] = tmp % 10;
        sum[j+1] += tmp / 10;
    }
}
int main()
{
    freopen("testdata/10106.in", "r", stdin);
    while (scanf("%s\n%s", x, y) != EOF)
    {
        memset(sum, 0, sizeof(sum));
        //printf("%s %s\n", x, y);
        int pos=0;
        int j=strlen(y)-1;
        for (; j>=0; --j)
        {
            multiply(y[j], pos);
            ++pos;
        }
        int k=699;
        for (; k>=0; --k)
            if (sum[k] != 0)
                break;
        if (k == -1)
            printf("0");
        for (;k>=0; --k)
            printf("%d", sum[k]);
        puts("");
    }
    return 0;
}
