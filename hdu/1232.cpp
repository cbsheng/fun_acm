#include <cstdio>
#define MMAX 1005

int father[MMAX];
int n, m;
void init()
{
	for (int i = 0; i < MMAX; ++i) father[i] = i;
}

int getfather(int n)
{
	/*递归写法, 在栈不爆的时候，效率较递归差
	int f, tmp;
	for (f = father[n]; f != father[f]; f = father[f]); //找出最远的祖先
	while (father[n] != f) {
		tmp = father[n];
		father[n] = f;
		n = tmp;
	}*/
	if (father[n] != n)
		father[n] = getfather(father[n]);
	return father[n];
}

void merge(int a, int b)
{
	int fa = getfather(a);
	int fb = getfather(b);
	if (fa != fb) {
		father[fb] = fa;
		n--;
	}
}

int main()
{
	//freopen("testdata/1232.txt", "r", stdin);
	int c1, c2;
	while (scanf("%d %d", &n, &m) != EOF && n) {
		 init();
		 for (int i = 0; i < m; ++i) {
		 	scanf("%d %d", &c1, &c2);
			merge(c1, c2);
		 }
		 printf("%d\n", n-1);
	}	
	return 0;
}