//Url:http://uva.onlinejudge.org/external/6/644.pdf

#include <cstdio>
#include <cstring>

int main()
{
    freopen("testdata/644.in", "r", stdin);
    char  cds[8][11];
    int   i=0, j, num=1, is=1;
    char  *less = NULL;
    char  *greater = NULL;
    while (scanf("%s", cds[i]) != EOF)
    {
        if (cds[i][0] == '9')
        {
            if (is) printf("Set %d is immediately decodable\n", num++);
            else printf("Set %d is not immediately decodable\n", num++);
            i = 0;
            is = 1;
            continue;
        }
        if (is)
            for (j=0; j<i; ++j)
            {
                greater = cds[i];
                less = cds[j];
                if (strlen(cds[j]) > strlen(cds[i]))
                {
                    greater = cds[j];
                    less = cds[i];
                }
                if (! strncmp(less, greater, strlen(less)))
                    is = 0;
            }
        ++i;
    }
    return 0;
}
