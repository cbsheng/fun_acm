//ST 算法
#include <cstdio>
#include <cmath>

#define MAXN (50000 + 10)

int cows[MAXN];
int st_max[MAXN][20];
int st_min[MAXN][20];
int n, q, l, r;

int max(int a, int b)
{
	return a < b ? b : a;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

void initst_max()
{
	for (int i = 0; i < n; i++) st_max[i][0] = cows[i];
	
	for (int j = 1; (1<<j) < n; ++j) {
		for (int i = 0; i + (1<<j) <= n; ++i) {
			st_max[i][j] = max(st_max[i][j-1], st_max[i+(1<<(j-1))][j-1]);
		}
	}
}

void initst_min()
{
	for (int i = 0; i < n; i++) st_min[i][0] = cows[i];
	
	for (int j = 1; (1<<j) < n; ++j) {
		for (int i = 0; i + (1<<j) <= n; ++i) {
			st_min[i][j] = min(st_min[i][j-1], st_min[i+(1<<(j-1))][j-1]);
		}
	}
}

int queryst_max(int l, int r)
{
	int k = (int)(log(r-l+1.0)/log(2.0));
	return max(st_max[l][k], st_max[r-(1<<k)+1][k]);
}

int queryst_min(int l, int r)
{
	int k = (int)(log(r-l+1.0)/log(2.0));
	return min(st_min[l][k], st_min[r-(1<<k)+1][k]);
}

int main()
{
	//freopen("testdata/3264.txt", "r", stdin);
	while (scanf("%d %d", &n, &q) != EOF) {
		for (int i = 0; i < n; ++i) scanf("%d", &cows[i]);
		initst_max();
		initst_min();
		while (q--) {
			scanf("%d %d", &l, &r);
			if (l == r) printf("0\n");
			else {
				int a = queryst_max(l-1, r-1);
				int b = queryst_min(l-1, r-1);
				printf("%d\n", a - b);
			}
		}
	}
	return 0;
}