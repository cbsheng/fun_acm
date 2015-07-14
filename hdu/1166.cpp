#include <cstdio>

#define maxn 50000
//4倍大小是一个合适的值
int ns[maxn * 4 + 100];
int nums[maxn]; //完全二叉树存储区间树

void build(int p, int l, int r)
{
	if (l == r) {
		ns[p] = nums[l-1];
	}
	else {
		int mid = (l + r) / 2;
		build((p<<1), l, mid);
		build((p<<1)+1, mid+1, r);
		ns[p] = ns[(p<<1)] + ns[(p<<1)+1];
	}
}

void add(int p, int l, int r, int n, int num)
{
	if (l == r) {
		ns[p] += num;
	}
	else {
		int mid = (l + r) / 2;
		if (n <= mid) add((p<<1), l, mid, n, num);
		else add((p<<1)+1, mid+1, r, n, num);
		ns[p] = ns[(p<<1)] + ns[(p<<1)+1];
	}
}

void sub(int p, int l, int r, int n, int num)
{
	if (l == r) {
		ns[p] -= num;
	}
	else {
		int mid = (l + r) / 2;
		if (n <= mid) sub((p<<1), l, mid, n, num);
		else sub((p<<1)+1, mid+1, r, n, num);
		ns[p] = ns[(p<<1)] + ns[(p<<1)+1];
	}
}

int query(int p, int l, int r, int ll, int rr)
{
	if (l == ll && r == rr) {return ns[p];}
	else {
		int mid = (l + r) / 2;
		if (rr <= mid) {return query((p<<1), l, mid, ll, rr);}
		else if (mid < ll) {return query((p<<1)+1, mid+1, r, ll, rr);}
		else {return query((p<<1), l, mid, ll, mid) + query((p<<1)+1, mid+1, r, mid+1, rr);}
	}
}

int main()
{
	//freopen("testdata/1166.txt", "r", stdin);
	int t, n, id, num, Case = 1;
	char input[30], opera[10];
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &nums[i]);
		build(1, 1, n);
		printf("Case %d:\n", Case++);
		getchar();
		while (fgets(input, sizeof(input), stdin)) {
			if (input[0] == 'E') break;
			sscanf(input, "%s %d %d", opera, &id, &num);
			if (opera[0] == 'Q') {
				printf("%d\n", query(1, 1, n, id, num));
			}
			else if (opera[0] == 'A') {
				add(1, 1, n, id, num);
			}
			else if (opera[0] == 'S') {
				sub(1, 1, n, id, num);
			}
		}
	}
	return 0;
}