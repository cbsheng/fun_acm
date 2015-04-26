//Url:http://uva.onlinejudge.org/external/107/10785.pdf

#include <cstdio>
#include <cstring>
#include <cstdlib>

char  vowel[]={"AUEOI"};
char  constant[]={"JSBKTCLDMVNWFXGPYHQZR"};
char  v[220];
char  c[220];

int cmp(const void*a, const void*b)
{
    return *(char*)a-*(char*)b;
}

int main()
{
    freopen("testdata/10785.in", "r", stdin);
    int  N, n, num=1;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &n);
        int  vn=0, cn=0;
        int  j=0, k=0;
        for (int i=0; i<n; ++i)
        {
            if (i%2 == 0)
            {
                v[vn++] = vowel[j];
                if (vn%21 == 0) j++;
            }
            else
            {
                c[cn++] = constant[k];
                if (cn%5 == 0) k++;
            }
        }
        qsort(v, vn, sizeof(char), cmp);
        qsort(c, cn, sizeof(char), cmp);
        printf("Case %d: ", num++);
        j = k = 0;
        for (int i=0; i<n; ++i)
            printf("%c", i%2==0 ? v[j++] : c[k++]);
        puts("");
    }
    return 0;
}
