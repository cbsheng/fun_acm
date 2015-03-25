#include <stdio.h>
#include <string.h>
int    p[20];
char   w[100];
void build(int *p, int n);
void getw_sequence();
int main()
{
	int    i;
	int    t, n;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &p[i]);
		build(p, n);
		getw_sequence();
		printf("\n");
	}
	return    0;
}

void build(int *p, int n)
{
	memset(w, '\0', sizeof(w));
	memset(w, '(', p[0]);
	w[p[0]] = ')';
	int    i;
	int    w_index = p[0] + 1;
	for (i = 1; i < n; i++)
	{
		memset(&w[w_index], '(', p[i] - p[i-1]);
		w_index += p[i] - p[i-1];
		w[w_index++] = ')';
	}
}

void getw_sequence()
{
	int    i = 0;
	int    n = 1;
	int    k, num = 1;
	while (w[i] != '\0')
	{
		if (w[i] == ')')
		{
			num = 1, n = 1;
			k = i;
			k--;
			while (n != 0)
			{
				if (w[k] == ')')
					n++, num++;
				if (w[k] == '(')
					n--;
				k--;
			}
			printf("%d ", num);
		}
		i++;
	}
}