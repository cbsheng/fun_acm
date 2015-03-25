#include <stdio.h>

const  double pi = 3.141592654;

int main()
{
	double    x, y;
	double    area;
	int       n, i;
	int       year;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%lf %lf", &x, &y);
		area = pi * (x*x + y*y);
		year = (int)area/100+1;
		printf("Property %d: This property will begin eroding in year %d.\n", i, year);
	}
	printf("END OF OUTPUT.");
	return    0;
}