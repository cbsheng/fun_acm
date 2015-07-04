#include <cstdio>
#include <cstring>

#define maxn 10000
#define wlen 10 //number长度
#define character '0'
#define size 10  

typedef struct node {
	int cnt; //记录访问量
	int child_num; //记录孩子个数
	int childs[size]; 
	void init()
	{
		cnt = 1;
		child_num = 0;
		memset(childs, 0, sizeof(childs));
	}
} Node;

char input[100];
Node ns[maxn * wlen];
int root;
int node_cnt = 0; //trie 树的结点数

int insert(char *s)
{
	int r = 0, index, child;
	for (int i = 0; s[i] != '\0'; ++i) {
		index = s[i] - character;
		child = ns[r].childs[index];
		if (child != 0) {
			ns[child].cnt++;
			r = child;
		}
		else {
			//以下这句考虑911和97625999分别不同顺序的情况
			if (i > 0 && ns[r].cnt > 1 && ns[r].child_num == 0) return 0;
			ns[++node_cnt].init();
			ns[r].childs[index] = node_cnt;
			ns[r].child_num++;
			r = node_cnt;
		}
	}
	if (ns[r].child_num != 0) { return 0;}
	else return 1;
}

int main()
{
	//freopen("testdata/3630.txt", "r", stdin);
	int t, n, flag;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		flag = 1;
		node_cnt = 0;
		ns[node_cnt].init(); //这里一定要清空
		while (n--) {
			scanf("%s", input);
			if (flag) {
				if (insert(input) == 0) flag = 0;
			}
		}
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}