//这题数据较水，没有负数，否则不能使用计数排序，会RE。
#include <cstdio>

#define MMAX 5003
#define NMAX 3000
int count[MMAX * 2];
int N[NMAX];

int main()
{
	//freopen("testdata/1280.txt", "r", stdin);
	int n, m, max;
	while (scanf("%d %d", &n, &m) != EOF) {
		for (int i = 0; i < MMAX * 2; ++i) count[i] = 0;
		for (int i = 0; i < n; ++i)
			scanf("%d", &N[i]);
		max = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (max < N[i] + N[j])
					max = N[i] + N[j];
				count[ N[i] + N[j] ]++;
			}
		}
		int num = 0, index = max;
		while (num != m) {
			if (count[max] > 0) {
				printf("%d", max);
				count[max]--;
				if (++num != m)
					printf(" ");
			}
			else {
				max--;
			}
		}
		printf("\n");
	}
	return 0;
}