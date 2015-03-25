#include <stdio.h>
#include <string.h>

typedef struct gird_point
{
	char    dire;
	int     flag;
} Point;

Point    p[10][10];

void fun(int l, int c,int s);

int main()
{
	int   i, j;
	int   low, col, sta;
	while (scanf("%d %d %d", &low, &col, &sta) && low != 0)
	{
		getchar();
		for (i = 0; i < low; i++)
		{
			for (j = 0; j < col; j++)
			{
				scanf("%c", &p[i][j].dire);
			}
			getchar();
		}
		fun(low, col, sta);
		memset(p, 0, sizeof(p));
		printf("\n");
	}
	return    0;
}

void fun(int l, int c,int s)
{
	int    i = 0, j = s - 1;
	int    all = 1;
	p[i][j].flag = all;
	int    k;
	while (1)
	{
		switch (p[i][j].dire)
		{
		case 'N':
			k = i;
			i = i - 1;
			if (i <= -1 )
			{
				printf("%d step(s) to exit", all);
				goto here;
			}
			if (p[i][j].flag != 0)
			{
				printf("%d step(s) before a loop of %d step(s)", p[i][j].flag - 1, p[k][j].flag - (p[i][j].flag - 1));
				goto here;
			}
			else
			{
				all++;
				p[i][j].flag = all;
				break;
			}
		case 'S':
			k = i;
			i = i + 1;
			if (i >= l)
			{
				printf("%d step(s) to exit", all);
				goto here;
			}
			if (p[i][j].flag != 0)
			{
				printf("%d step(s) before a loop of %d step(s)", p[i][j].flag - 1, p[k][j].flag - (p[i][j].flag - 1));
				goto here;
			}
			else
			{
				all++;
				p[i][j].flag = all;
				break;
			}
		case 'E':
			k = j;
			j = j + 1;
			if (j >= c)
			{
				printf("%d step(s) to exit", all);
				goto here;
			}
			if (p[i][j].flag != 0)
			{
				printf("%d step(s) before a loop of %d step(s)", p[i][j].flag - 1, p[i][k].flag - (p[i][j].flag - 1));
				goto here;
			}
			else
			{
				all++;
				p[i][j].flag = all;
				break;
			}
		case 'W':
			k = j;
			j = j - 1;
			if (j <= -1)
			{
				printf("%d step(s) to exit", all);
				goto here;
			}
			if (p[i][j].flag != 0)
			{
				printf("%d step(s) before a loop of %d step(s)", p[i][j].flag - 1, p[i][k].flag - (p[i][j].flag - 1));
				goto here;
			}
			else
			{
				all++;
				p[i][j].flag = all;
				break;
			}
		}
	}
here:
	return;
}