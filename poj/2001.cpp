#include <cstring>
#include <cstdio>

#define maxn 1010

typedef struct node {
	int cnt;
	int childs[26];
	void init() {
		cnt = 1;
		memset(childs, -1, sizeof(childs));
	}
} Node;

Node ns[maxn * 100];
char input[maxn][100];
int root;
int node_num;

int create()
{
	node_num = 0;
	ns[node_num].init();
	return node_num;
}

void insert(int root, char *s)
{
	if (*s == '\0') return;
	int index = *s - 'a';
	int child = ns[root].childs[index];
	if (child != -1) {
		ns[child].cnt++;
		insert(child, s+1);
		return;
	}
	else {
		node_num++;
		ns[node_num].init();
		
		ns[root].childs[index] = node_num;
		insert(node_num, s+1);
		return;
	}
}

void query(int root, char *s)
{//如果某个字符所在的结点 cnt 值是1，那到这个字符为止的都是最短前缀。
 //或者该字符串遍历完毕也找不到 cnt 为1的，那整个字符串都是最短前缀。
 //具体画图则可以观察到。
	printf("%s ", s);
	char *p = s;
	int index = *s++ - 'a';
	int child = ns[root].childs[index];
	while (*s != '\0' && ns[child].cnt != 1) {
		index = *s++ - 'a';
		child = ns[child].childs[index];
	}
	*s = '\0';
	printf("%s\n", p);
}

int main()
{
	//freopen("testdata/2001.txt", "r", stdin);
	root = create();
	int num = 0 ;
	while (scanf("%s", &input[num][0]) != EOF) insert(root, &input[num++][0]);
	for (int i = 0; i < num; ++i) query(root, &input[i][0]);
	
	return 0;
}