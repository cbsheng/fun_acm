/*
Url : http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=94&page=show_problem&problem=1241
author : cbsheng
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int  n, farmers, framyard, animals, value;
	int  premium;
	scanf("%d", &n);
	while (n-- && scanf("%d", &farmers))
	{
		premium = 0;
		while (farmers-- && scanf("%d %d %d", &framyard, &animals, &value))
			premium += framyard * value;
		printf("%d\n", premium);
	}
	return 0;
}