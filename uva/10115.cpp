//url:http://uva.onlinejudge.org/external/101/10115.pdf

#include <cstdio>
#include <cstring>

struct Rules {
    char find[80];
    char replace[80];
    int  lf;
    int  lr;
}rs[10];

int main()
{
    freopen("testdata/10115.in", "r", stdin);
    int  rs_num;
    char text[1000], res[1000];
    scanf("%d", &rs_num);
    getchar();
    while (rs_num != 0)
    {
        for (int i=0; i<rs_num; ++i)
        {
            fgets(rs[i].find, 80, stdin);
            fgets(rs[i].replace, 80, stdin);
            rs[i].lf = strlen(rs[i].find)-1;
            rs[i].lr = strlen(rs[i].replace)-1;
            rs[i].find[rs[i].lf] = '\0';
            rs[i].replace[rs[i].lr] = '\0';
        }
        fgets(text, 1000, stdin);
        for (int i=0; i<rs_num; ++i)
        {
            int matching=1;
            char *pos=NULL;
            while (matching)
            {
                pos = strstr(text, rs[i].find);
                if (NULL == pos)
                {
                    matching = 0;
                }
                else
                {
                    sprintf(res, "%s", pos+rs[i].lf);
                    sprintf(pos, "%s", rs[i].replace);
                    sprintf(pos+rs[i].lr, "%s", res);
                }
            }
        }
        printf("%s", text);

        scanf("%d", &rs_num);
        getchar();
    }
    return 0;
}
