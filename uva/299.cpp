//Url:http://uva.onlinejudge.org/external/2/299.pdf

#include <cstdio>

int main()
{
    freopen("testdata/299.in", "r", stdin);
    int  l[51];
    int  n, ll, c;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &ll);
        for (int i=0; i<ll; ++i) scanf("%d", &l[i]);
        c = 0;
        for (int i=1; i<ll; ++i)
            for (int j=0; j<=i; ++j)
                if (l[j] > l[i])
                {
                    int tmp = l[j];
                    l[j] = l[i];
                    l[i] = tmp;
                    ++c;
                }
        printf("Optimal train swapping takes %d swaps.\n", c);
    }
    return 0;
}
