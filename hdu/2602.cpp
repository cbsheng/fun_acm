//url:http://acm.hdu.edu.cn/showproblem.php?pid=2602

#include <cstdio>
#include <cstring>

int N[1000], V[1000], F[1000][1000];

int main()
{
    int t, n, v;
    scanf("%d", &t);
    while (t--)
    {
        memset(F, 0, sizeof(F));

        scanf("%d %d", &n, &v);
        for (int i=1; i<=n; ++i)
            scanf("%d", &N[i]);
        for (int i=1; i<=n; ++i)
            scanf("%d", &V[i]);

        for (int i=1; i<=n; ++i)
        {
            for (int j=0; j<=v; ++j)
            {
                if (V[i] <= j && F[i-1][j-V[i]] + N[i] > F[i-1][j])
                    F[i][j] = F[i-1][j-V[i]] + N[i];
                else
                    F[i][j] = F[i-1][j];
            }
        }
        printf("%d\n", F[n][v]);
    }
    return 0;
}
