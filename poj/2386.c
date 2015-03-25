#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define     ROW 100
#define     COL 100

typedef struct node {
	char	data;
	int		signal;
} Node;			
Node    grid[ROW][COL];

int    num;
int    m, n;

void fun(int m, int n);
void dfs(Node (*p)[COL], int i, int j);

int main(int argc, char *argv[])
{
	int    i, j; // Loop variables anywhere 
	char   a[10];

	scanf("%d %d", &m, &n);
	gets(a);

	memset(grid, 0, sizeof(grid));
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%c", &grid[i][j].data);
		}
		gets(a);
	}
	fun(m, n);
	return    0;
}

void fun(int m, int n)
{
	int    i, j;
	int    total = 0;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (grid[i][j].signal == 1) {
				continue;
			}
			if (grid[i][j].signal == 0 && grid[i][j].data == 'W') {
				num = 0;
				dfs(grid, i, j);
				if (num > 0) {
					total += 1;
				}
			}
		}
	}		

	printf("%d\n", total);
}

void dfs(Node (*p)[COL], int i, int j)
{
	if (i < 0 || i > (m-1) || 
		j < 0 || j > (n-1) ||
		p[i][j].signal == 1  ) {
		return;
	}

	if (p[i][j].data == 'W' && p[i][j].signal == 0) {
		p[i][j].signal = 1;
		num++;
		dfs(p, i-1, j-1);
		dfs(p, i-1, j);
		dfs(p, i-1, j+1);

		dfs(p, i, j-1);
		dfs(p, i, j+1);

		dfs(p, i+1, j-1);
		dfs(p, i+1, j);
		dfs(p, i+1, j+1);
	}
}