#include <cstdio>
#include <cstdlib>

#define maxn 100010

typedef struct node {
	int cnt;
    int childs[26];
} Node;

char input[100];
Node ns[maxn * 10];
int  root; //根节点
int  node_num; //总结点数

int create()
{ //创建一颗空的 trie 树
    node_num = 0;
    ns[node_num].cnt = -1;
    for (int i = 0; i < 26; ++i) ns[node_num].childs[i] = -1;
    return node_num;
}

void insert(int root, char *s)
{ //将一个字符串插入到 trie 树中
    if (*s == '\0') return;
    int index = *s - 'a';
    int child = ns[root].childs[*s - 'a'];
    if (child != -1) {
        ns[child].cnt++;//如果有这个孩子，就将这个孩子的数量加一。
        insert(child, s+1);//然后从这个孩子开始继续插入。
        return;
    }
    else {
        node_num++;
        ns[node_num].cnt = 1;
        for (int i = 0; i < 26; ++i) ns[node_num].childs[i] = -1;
        
        ns[root].childs[index] = node_num;
        insert(node_num, s+1);
        return;
    }
}

int query(int root, char *s)
{//在 trie 树中查询一个字符串
    int index = *s - 'a';
    int child = ns[root].childs[index];
    if (child != -1) {
        if (*(s+1) == '\0') return ns[child].cnt;
        else return query(child, s+1);
    }
    return 0;
}


int main()
{
	//freopen("testdata/1014.txt", "r", stdin);
	int n, m;
    scanf("%d", &n); 
    root = create();
	for (int i = 0; i < n; ++i) {
		scanf("%s", input);
        insert(root, input);
	}
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%s", input);
        printf("%d\n", query(root, input));
    }
	return 0;
}
