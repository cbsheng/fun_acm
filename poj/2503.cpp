//这题是 trie 树 和 哈希 的入门题。
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

#define maxn 100010

typedef struct node {
	char word[12];
	int childs[26];
	void init() { memset(childs, -1, sizeof(childs)); }
} Node;

Node ns[maxn * 10];
char ew[12], fw[12];
int node_num;
int root;

void insert(char *e, char *f)
{
	int r = 0, index;
	for (int i = 0; f[i] != '\0'; ++i) {
		index = f[i] - 'a';
		if (ns[r].childs[index] == 0) {
			ns[r].childs[index] = ++node_num;
			r = node_num;
		}
		else 
		r = ns[r].childs[index];
	}
	strcpy(ns[r].word, e);
}

void query(char *f)
{
	int r = 0, index;
	for (int i = 0; f[i] != '\0'; ++i) {
		index = f[i] - 'a';
		if (ns[r].childs[index] == 0) {
			printf("eh\n");
			return;
		}
		else {
			r = ns[r].childs[index];
		}
	}
	printf("%s\n", ns[r].word);
	return;
}

int main()
{
	//freopen("testdata/2503.txt", "r", stdin);
	node_num = 0;
	string s;
	while (getline(cin, s)) { //输入还用 fgets + sscanf 会快一大半。
		if (s.length() > 0) {
			istringstream stream(s);
			stream >> ew >> fw;
			insert(ew, fw);
		}
		else
			break;
	}
	while (scanf("%s", fw) != EOF)  query(fw);
	return 0;
}