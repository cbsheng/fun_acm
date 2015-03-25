#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define     ROW  20
#define     COL  20

typedef struct square_
{
	char    data;
	int     signal;
} Square;

Square    square[ROW][COL];
int       W, H;
int       num;

void dfs(int pos_w, int pos_h);

int main(int argc, char *argv[])
{
	int    i, j;
	int    pos_W, pos_H;
	char   a[10];

	while (1) {
		scanf("%d %d", &W, &H);
		gets(a);

		if (W == 0 || H == 0) {
			return    0;
		}

		memset(square, 0, sizeof(square));
		for (i = 0; i < H; i++) {
			for (j = 0; j < W; j++) {
				scanf("%c", &square[i][j].data);
				if (square[i][j].data == '@') {
					pos_W = j;
					pos_H = i;
				}
			}
			gets(a);
		}
		num = 0;
		dfs(pos_W, pos_H);
		printf("%d\n", num);
	}
	return    0;
}

void dfs(int pos_w, int pos_h)
{
	if (pos_w < 0 || pos_w > (W-1) ||
		pos_h < 0 || pos_h > (H-1) ||
		square[pos_h][pos_w].signal == 1 ||
		square[pos_h][pos_w].data == '#'
		) {
		return;
	}
	if ( (square[pos_h][pos_w].data == '.' && square[pos_h][pos_w].signal == 0 ) 
		|| square[pos_h][pos_w].data == '@') {
		num++;
		square[pos_h][pos_w].signal = 1;

		dfs(pos_w-1, pos_h);
		dfs(pos_w+1, pos_h);

		dfs(pos_w, pos_h-1);
		dfs(pos_w, pos_h+1);
	}
}