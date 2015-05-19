//url:http://acm.hdu.edu.cn/showproblem.php?pid=2046

#include <cstdio>

int main()
{
    //freopen("testdata/2046.in", "r", stdin);
    int t;
    __int64 dp[51];
    dp[1] = 1;
    dp[2] = 1;
    for (int i=3; i<51; ++i)
        dp[i] = dp[i-1] + dp[i-2];
    while (scanf("%d", &t) != EOF)
        printf("%I64d\n", dp[t]);
    return 0;
}
