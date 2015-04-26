//Url:http://uva.onlinejudge.org/external/4/400.pdf

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

char  fs[101][65];

int cmp(const void *a, const void *b)
{
    return strcmp((char*)a, (char*)b);
}

int main()
{
    freopen("testdata/400.in", "r", stdin);
    int  n;
    int  max;
    while (scanf("%d", &n) != EOF)
    {
        max = 0;
        memset(fs, 0, sizeof(fs));
        for (int i=0; i<n; ++i)
        {
            scanf("%s", &fs[i][0]);
            if (strlen(fs[i]) > max)
                max = strlen(fs[i]);
        }
        qsort(fs, n ,sizeof(fs[0]), cmp);
        int col = 62 / (max+2);
        int row = n / col + (n % col != 0 ? 1 : 0);
        printf("------------------------------------------------------------\n");
        for (int i=0; i<row; ++i)
        {
            for (int j=0; j<col; ++j)
                if (i+j*row < n)
                    printf("%-*s", max+2, fs[i+j*row]);
            puts("");
        }
    }
    return 0;
}
