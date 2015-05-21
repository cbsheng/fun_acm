//url:http://acm.hdu.edu.cn/showproblem.php?pid=1257

#include <cstdio>

int main()
{
    freopen("testdata/1257.in", "r", stdin);
    int  dp[100];
    int  num, t, input;
    while (scanf("%d", &t) != EOF)
    {
        num = 0;
        dp[0] = 0;
        while (t--)
        {
            scanf("%d", &input);
            int k = -1;
            int min = 99999999;
            for (int j=0; j<=num; ++j)
            { //找最贴近它的
                int tmp = dp[j] - input;
                if (tmp > 0 && tmp < min)
                {
                    k = j;
                    min = tmp;
                }
            }
            if (k == -1)
            //需要增加一个系统
                dp[++num] = input;
            else
                dp[k] = input;
        }
        printf("%d\n", num);
    }
    return 0;
}
