#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define maxn 200005
#define maxm maxn * 2

char input[maxn];
char str[maxm] = {'$', '#'};
int  p[maxm];

int longest_plalindrome(char *s, int *mxlen, int *index)
{//p[i] = min{p[2 * id - 1], mx - i}
	int len = strlen(s);
	int id = 0, mx = 0;
	*mxlen = 0;
	for (int i = 1; s[i] != '\0'; ++i) {
		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
		while (s[i + p[i]] == s[i - p[i]]) p[i]++;
		if ((i + p[i]) > mx) {
			mx = i + p[i];
			id = i;
		}
		if (*mxlen < p[i]) {
			*mxlen = p[i];
			*index = i;
		}
	}
	*mxlen -= 1;
	return *mxlen;
}

int main()
{
	//freopen("testdata/3294.txt", "r", stdin);
	char c;
	int  d, len, pos, mxlen, index;
	while (scanf("%c %s", &c, input) != EOF) {
		d = c - 'a';
		len = strlen(input);
		pos = 2;
		for (int i = 0; input[i] != '\0'; ++i) {
			//step 1
			if (input[i] < c)
				input[i] = 'z' - (c - input[i] - 1);
			else
				input[i] -= d;
			str[pos++] = input[i];
			str[pos++] = '#';
		}
		str[pos] = '\0';
		longest_plalindrome(str, &mxlen, &index); //step 2
		if (mxlen < 2) 
			printf("No solution!\n");
		else {
			int beg = (index - (mxlen - 2)) / 2 - 1;
			printf("%d %d\n", beg, beg + mxlen - 1);
			for (int i = beg; i < beg + mxlen; ++i)
				printf("%c", input[i]);
			printf("\n");
		}
		getchar();
	}
	return 0;
}