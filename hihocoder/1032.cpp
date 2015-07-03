#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define maxn 1000005
#define maxm maxn * 2

char input[maxn];
char str[maxm];
int  p[maxm];

int longest_plalindrome(char *s)
{//p[i] = min{p[2 * id - 1], mx - i}
	int len = strlen(s);
	int id = 0, mx = 0, max = 0;
	for (int i = 1; s[i] != '\0'; ++i) {
		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
		while (s[i + p[i]] == s[i - p[i]]) p[i]++;
		if ((i + p[i]) > mx) {
			mx = i + p[i];
			id = i;
		}
		if (max < p[i]) max = p[i];
	}
	return max - 1;
}
int main()
{
	//freopen("testdata/1032.txt", "r", stdin);
	int t, len, pos;
	scanf("%d", &t);
	for (int k = 0; k < t; ++k) {
		scanf("%s", input);
		len = strlen(input);
		str[0] = '$';
		str[1] = '#';
		pos = 2;
		for (int i = 0; input[i] != '\0'; ++i) {
			str[pos++] = input[i];
			str[pos++] = '#';
		}
		str[pos] = '\0';
		
		printf("%d\n", longest_plalindrome(str));
	}
	return 0;
}