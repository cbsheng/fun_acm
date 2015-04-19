#include <cstdio>
#include <cstring>

int main()
{
    freopen("testdata/537.in", "r", stdin);
    int t, i=1, j, fgp, fgv, fga;
    char input[30], content[2000];
    char pp[3], vv[3], aa[3];
    double p, v, a;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        memset(content, 0, sizeof(content));
        fgets(content, sizeof(content), stdin);
        fgp = fga = fgv = 0;
        char *tok = strtok(content, " ");
        while (tok)
        {
            if (tok[1] == '=')
            {
                switch (tok[0])
                {
                    case 'P':
                        sscanf(tok+2, "%lf%s", &p, pp);
                        if (pp[0] == 'm')
                            p /= 1000;
                        if (pp[0] == 'M')
                            p *= 1000000;
                        if (pp[0] == 'k')
                            p *= 1000;
                        fgp = 1;
                        break;
                    case 'U':
                        sscanf(tok+2, "%lf%s", &v, vv);
                        if (vv[0] == 'm')
                            v /= 1000;
                        if (vv[0] == 'M')
                            v *= 1000000;
                        if (vv[0] == 'k')
                            v *= 1000;
                        fgv = 1;
                        break;
                    case 'I':
                        sscanf(tok+2, "%lf%s", &a, aa);
                        if (aa[0] == 'm')
                            a /= 1000;
                        if (aa[0] == 'M')
                            a *= 1000000;
                        if (aa[0] == 'k')
                            a *= 1000;
                        fga = 1;
                        break;
                    default:
                        break;
                }
            }
            tok = strtok(NULL, " ");
        } //end of while
        if (!fgp)
            printf("Problem #%d\nP=%.2fW\n\n", i++, v*a);
        else if (!fgv)
            printf("Problem #%d\nU=%.2fV\n\n", i++, p/a);
        else
            printf("Problem #%d\nI=%.2fA\n\n", i++, p/v);
    }
    return 0;
}
