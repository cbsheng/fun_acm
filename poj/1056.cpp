#include <cstdio>
#include <cstring>

#define maxn 10
#define wlen 10 //单词长度
#define character '0'
#define size 2 

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

Node ns[maxn * wlen];
int root;
int node_cnt = 0; //trie 树的结点数
char input[12];

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
			if (i > 0 && ns[r].cnt > 1 && ns[r].child_num == 0) return 0;
			ns[++node_cnt].init();
			ns[r].childs[index] = node_cnt;
			ns[r].child_num++;
			r = node_cnt;
		}
	}
	if (ns[r].child_num != 0) return 0;
	else return 1;
}

int query(char *s)
{
	int r = 0, index, child;
	for (int i = 0; s[i] != '\0'; ++i) {
		index = s[i] - character;
		child = ns[r].childs[index];
		if (child == 0) {
			return 0;
		} 
		else {
			r = child;
		}
	}
	return ns[r].cnt;
}

int main()
{
	//freopen("testdata/1056.txt", "r", stdin);
	int flag = 1, c = 1;
	while (scanf("%s", input) != EOF) {
		if (input[0] == '9') {
			node_cnt = 0;
			ns[node_cnt].init();
			if (flag) printf("Set %d is immediately decodable\n", c++);
			else printf("Set %d is not immediately decodable\n", c++);
			flag = 1;
			continue;
		}
		if (flag) {
			if (insert(input) == 0) flag = 0;			
		}
		
	}
	return 0;
}