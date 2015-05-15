//Url:http://poj.org/problem?id=1163
#include <cstdio>

int F[10000][10000];
int triangle[10000][10000];

int main()
{
    freopen("testdata/1163.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i)
        for (int j=0; j<i+1; ++j)
            scanf("%d", &triangle[i][j]);

    for (int i=0; i<n; ++i)
        F[n-1][i] = triangle[n-1][i];

    for (int i=n-2; i>=0; --i)
    {
        for (int j=0; j<=i; ++j)
        {
            if (F[i+1][j] > F[i+1][j+1])
                F[i][j] = triangle[i][j] + F[i+1][j];
            else
                F[i][j] = triangle[i][j] + F[i+1][j+1];
        }
    }
    printf("%d\n", F[0][0]);
    return 0;
}
