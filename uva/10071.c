/*
Url : http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=94&page=show_problem&problem=1012
Author : cbsheng
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int  v, t;
	while (scanf("%d %d", &v, &t) != EOF)
		printf("%d\n", (2 * v * t));
	return 0;
}