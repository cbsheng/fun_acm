//Url:http://uva.onlinejudge.org/external/4/409.pdf

#include <cstdio>
#include <cstring>
#include <cctype>

int main()
{
    freopen("testdata/409.in", "r", stdin);
    int  k, e, i, j, h;
    char tx[20][80];
    char kws[20][30];
    char o[20][80];
    int  cnt[20];
    int  num=1;
    while (scanf("%d %d\n", &k, &e) != EOF)
    {
        int max = 0;
        memset(kws, '0', sizeof(kws));
        memset(tx, '0', sizeof(tx));
        memset(cnt, 0, sizeof(cnt));
        for (i=0; i<k; ++i)
            gets(kws[i]);
        for (i=0; i<e; ++i)
        {
            fgets(tx[i], sizeof(tx[i]), stdin);
            int len=strlen(tx[i]);
            strncpy(o[i], tx[i], sizeof(o[i]));
            for (j=0; j<len; ++j)
                if (! isalpha(tx[i][j]))
                    tx[i][j] = 0;

            for (j=0; j<len; ++j)
                if (tx[i][j] != 0)
                    for (h=0; h<k; ++h)
                        if (! strcasecmp(&tx[i][j], kws[h]))
                            cnt[i] += 1;
            if (max < cnt[i])
                max = cnt[i];
        }
        printf("Excuse Set #%d\n", num++);
        for (i=0; i<e; ++i)
            if (cnt[i] == max)
                printf("%s", o[i]);
        puts("");
    }
    return 0;
}
