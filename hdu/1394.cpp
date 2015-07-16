#include <cstdio>

#define MAXN (5000 + 10)
#define lson rt << 1
#define rson rt << 1 | 1

int ns[MAXN << 2];
int nums[MAXN];
int n, input, sum, ans;

void build(int rt, int l, int r)
{
	if (l == r) ns[rt] = 0;
	else {
		int mid = (l + r) / 2;
		build(lson, l, mid);
		build(rson, mid+1, r);
		ns[rt] = ns[lson] + ns[rson];
	}
}

int query(int rt, int l, int r, int ll, int rr)
{
	
	if (l == ll && rr == r) return ns[rt];
	else {
		int mid = (l + r) / 2;
		if (rr <= mid) return query(lson, l, mid, ll, rr);
		else if (mid < ll) return query(rson, mid+1, r, ll, rr);
		else {
			return query(lson, l, mid, ll, mid) + query(rson, mid+1, r, mid+1, rr);
		}
	}
}

void update(int rt, int l, int r, int id)
{
	if (l == id && r == id) ns[rt] = 1;
	else {
		int mid = (l + r) / 2;
		if (id <= mid)  update(lson, l, mid, id);
		else update(rson, mid+1, r, id);
		ns[rt] = ns[lson] + ns[rson];
	}
}

int main()
{
	//freopen("testdata/1394.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		build(1, 0, n);
		sum = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &nums[i]);
			sum += query(1, 0, n, nums[i]+1, n);
			update(1, 0, n, nums[i]);
		}
		ans = sum;
		for (int i = 0; i < n-1; ++i) {
			//sum -= query(1, 0, n, 0, nums[i]-1); //这种方式同样是先减后加
			//sum += query(1, 0, n, nums[i]+1, n); //不过需要注意nums[i]-1会等于-1.这时通过对nums[i]+1进行处理，而 n 就需要+1.
			sum = sum - nums[i] + (n - nums[i] - 1);
			if (ans > sum) ans = sum;
		}
		
		printf("%d\n", ans);
	}
}