//线段树单点更新，完全二叉树解法
#include <cstdio>

#define MAXN 200000
#define lson rt<<1
#define rson rt<<1|1

int top[MAXN * 4 + 100];
int students[MAXN + 10];

int k;

void pushup(int rt)
{
	top[rt] = top[lson] > top[rson] ? top[lson] : top[rson];
}

void build(int rt, int l, int r)
{
	if (l == r) {
		scanf("%d", &k);
		top[rt] = k;
	}
	else {
		int mid = (l + r) / 2;
		build(lson, l, mid);
		build(rson, mid+1, r);
		pushup(rt);
	}
}

void add(int rt, int l, int r, int node, int num)
{
	if (l == r) {
		top[rt] = num;
	}
	else {
		int mid = (l + r) / 2;
		if (node <= mid) {add(lson, l, mid, node, num);}
		else {add(rson, mid+1, r, node, num);}
		pushup(rt);
	}
}

int query(int rt, int l, int r, int ll, int rr)
{
	if (l == ll && r == rr) {
		return top[rt];
	}
	else {
		int mid = (l + r) / 2;
		if (rr <= mid) return query(lson, l, mid, ll, rr);
		else if (mid < ll) return query(rson, mid+1, r, ll, rr);
		else {
			//注意最后两个参数也要做相应的变动
			int a = query(lson, l, mid, ll, mid); 
			int b = query(rson, mid+1, r, mid+1, rr);
			return a > b ? a : b;
		}
	}
}

int main()
{
	//freopen("testdata/1754.txt", "r", stdin);
	int n, m, left, right;
	char c;
	while (scanf("%d %d", &n, &m) != EOF) {
		build(1, 1, n);
		for (int i = 0; i < m; ++i) {
			getchar();
			scanf("%c %d %d", &c, &left, &right);
			if (c == 'Q') {
				printf("%d\n", query(1, 1, n, left, right));
			}
			else if (c == 'U') {
				add(1, 1, n, left, right);
			}
		}
	}
	return 0;
}