#include <cstdio>

int dp[15][15];
int t, m, n;

void caldp()
{
	dp[0][0] = 1;
	for (int i = 1; i < 15; ++i) { //盘子
		for (int j = 0; j < 15; ++j) { //苹果
			if (i <= j) dp[j][i] = dp[j - i][i] + dp[j][i-1];
			else dp[j][i] = dp[j][j];
		}
	}
}

int main()
{
	//freopen("testdata/1664.txt", "r", stdin);
	scanf("%d", &t);
	caldp();
	while (t--) {
		scanf("%d %d", &m, &n);
		printf("%d\n", dp[m][n]);
	}
	return 0;
}