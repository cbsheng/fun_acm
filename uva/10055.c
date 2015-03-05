/*
Url : http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=94&page=show_problem&problem=996
author : cbsheng
*/

#include <stdio.h>

int main()
{
	long int own, opponent;
	while (scanf("%ld %ld", &own, &opponent) == 2)
		printf("%ld\n", own > opponent ? (own - opponent) : (opponent - own));
	return 0;
}