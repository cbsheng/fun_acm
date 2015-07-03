#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 110005
#define maxm maxn * 2

char input[maxn];
char str[maxm] = {'$', '#'};
int  p[maxm];

int longest_plalindrome_substring(char *s)
{//p[i] = min{p[2 * id - 1], mx - i}
	int pos = 2;
	for (int i = 0; s[i] != '\0'; ++i) {
			str[pos++] = s[i];
			str[pos++] = '#';
		}
	str[pos] = '\0';
	
	int id = 0, mx = 0, max = 0;
	for (int i = 1; str[i] != '\0'; ++i) {
		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
		while (str[i + p[i]] == str[i - p[i]]) p[i]++;
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
	//freopen("testdata/3068.txt", "r", stdin);
	while (scanf("%s", input) != EOF) {
		printf("%d\n", longest_plalindrome_substring(input));
		getchar();
		getchar();
	}
	return 0;
}