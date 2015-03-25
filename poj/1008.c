#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char    haab[20][10] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax",
						    "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
	char    holly[20][10] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok",
						     "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
	int    ye, da;
	char   mo[10];
	int    all_day;
	int    n;
	int    i;
	scanf("%d", &n);
	printf("%d\n", n);
	while (n-- && scanf("%d. %s %d", &da, mo, &ye))
	{
		for (i = 0; i < 20; i++)
		{
			if (!strcmp(haab[i], mo))
				break;
		}
		all_day = ye * 365 + 20 * i + da;
		printf("%d %s %d\n", all_day % 260 % 13 + 1,
							 holly[all_day % 260 % 20],
							 all_day / 260 );
	}
	return    0;
}