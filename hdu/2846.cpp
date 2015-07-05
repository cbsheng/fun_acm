#include <cstdio>
#include <cstring>

#define maxn 100010 //10万
#define wlen 20 //单词长度
#define character 'a'
#define SIZE 26  //26个字母

typedef struct node {
	int cnt; //记录访问量
	int id; //记录是否同一个源字符串
	int childs[SIZE]; 
	void init()
	{
		id = -1;
		cnt = 0;
		memset(childs, 0, sizeof(childs));
	}
} Node;

Node ns[maxn * wlen];
int root;
int node_cnt = 0; //trie 树的结点数
char input[30];

void insert(char *s, int id)
{//建立以后缀为主的 trie 树，例如字符串 abcdae ，各个后缀是 abcdae,bcdae,cdae,dae,ae,e
 //避免重复计算，例如 abcdae 和 ae 两个子串。所以要增加一个 id 标识是否同一个源字符串。
	int r = 0, index, child;
	for (int i = 0; s[i] != '\0'; ++i) {
		index = s[i] - character;
		child = ns[r].childs[index];
		if (child != 0) {
			r = child;
		}
		else {
			ns[++node_cnt].init();
			ns[r].childs[index] = node_cnt;
			r = node_cnt;
		}
		if (ns[r].id != id) ns[r].cnt++;
		ns[r].id = id;
	}
}

int query(char *s)
{
	int r = 0;
	int index, child;
	for (int i = 0; s[i] != '\0'; ++i) {
		index = s[i] - character;
		child = ns[r].childs[index];
		if (child == 0) {
			return 0;
		}
		r = child;
	}
	return ns[r].cnt;
}

int main()
{
	//freopen("testdata/2846.txt", "r", stdin);
	int p, q;
	ns[node_cnt = 0].init();
	scanf("%d", &p);
	while (p--) {
		scanf("%s", input);
		for (int i = 0; i < strlen(input); ++i) {
			insert(input+i, p+1);
		}
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%s", input);
		printf("%d\n", query(input));
	}
	return 0;
}

/* 这个query 查询的树是以前缀为主。在这题会超时。
int query(int root, char *s)
{
	int sum = 0;
	int index = *s - character;
	int child = ns[root].childs[index];
	for (int i = 0; i < 26; ++i) {
		int i = ns[root].chds[j];
		if (ns[root].childs[i] != 0) {
			if (i == index) {
				if (*(s+1) == '\0') {
					//剪枝
					sum += ns[ns[root].childs[i]].cnt;
					break;
				}
				else 
					sum += query(ns[root].childs[i], s+1);
			}
			else
				sum += query(ns[root].childs[i], s);
		}
	}
	return sum;
}*/
