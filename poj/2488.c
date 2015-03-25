#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int    flag[8][2] = {{1,-2},{-1,-2},{2,-1},{-2,-1},{2,1},{-2,1},{1,2},{-1,2}};
int    chessboard[30][30];
int    sx[30], sy[30];
int    p, q;  // p is row, q is col
int    sum;
int    sign;

void dfs(int i, int j);

int main(int argc, char *argv[])
{
	int    n;
	int    i, j;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		memset(chessboard, 0, sizeof(chessboard));
		scanf("%d %d", &p, &q);

		if (p*q < 1) {
			printf("Scenario #%d:\nimpossible\n", i+1);
			if (i != n-1) {
				printf("\n");
			}
		}
		
		sum = 0;
		sign = 0;
		dfs(p-1, 0);
	    printf("Scenario #%d:\n", i+1);
	    if (sign)
	    {
		   for (j = 0; j < p * q; j++)
		   {
			 /* 注意棋盘行(y)是字母，列(x)是数字 */
			 printf("%c%d", sy[j] + 64, sx[j]);
		   }
		   printf("\n");
		}
		else
		{
		   printf("impossible\n");
		}
		/* 最后一组数据没空行 */
		 if (i != n-1) printf("\n");
	}
	return    0;
}

void dfs(int i, int j)
{
		/*
		 * * 4 * 6 *
		 * 2 * * * 8
		 * * * # * *
		 * 1 * * * 7
		 * * 3 * 5 *
		 */
	int     x, y, k;
	if (sign) {
		return;
	}
	if ((chessboard[i][j] == 0) && i >= 0 && i < p && j >= 0 && j < q ) {
		chessboard[i][j] = 1;
		//sx记录数字， sy记录字母
		//数字对应行， 字母对应列
		sx[sum] = p-i;
		sy[sum] = j+1;
		sum++;
		if (sum == p*q) {
			sign = 1;
			return;
		}
		for (k = 0; k < 8; k++) {
			x = i + flag[k][0];
			y = j + flag[k][1];
			dfs(x, y);
		}
		sum--;
		chessboard[i][j] = 0;
	}
}