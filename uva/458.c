/*
Url : http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=94&page=show_problem&problem=399
Author  :cbsheng
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char  code[2000];
	int  i;
	while (fgets(code, 2000, stdin))
	{
		for (i = 0; code[i] != '\n'; ++i)
			printf("%c", code[i] - 7);
		printf("\n");
	}
	return 0;
}