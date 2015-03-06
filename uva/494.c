/*
Url : http://uva.onlinejudge.org/external/4/494.pdf
Author : cbsheng
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	int   count, i, isword;
	char  sentence[1000];
	while (fgets(sentence, 2000, stdin))
	{
		count = 0;
		isword = 1;
		for (i = 0; sentence[i] != '\n'; i++)
		{
			if (isalpha(sentence[i]) && isword)
			{
				isword = 0;
				++count;
			}
			else if (!isalpha(sentence[i]) && !isword)
			{
				isword = 1;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}