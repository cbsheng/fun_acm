//hdu id 5272
#include <cstdio>

using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	int t, flag;
	long long n, tmp;
	long long g, num;
	scanf("%d", &t);
	while (t--) {
		g = 0;
		num = 0;
		flag = 1;
		scanf("%lld", &n);
		if (n == 0)  {
			printf("0\n");
			continue;
		}
		while (n) {
			if (n % 2) {
				num = 1;
			}	
			else {
				flag = 0;
				g += num;
				num = 0;
			}
			n /= 2;
		}
		if (flag) g = 1;
		else g += num;
		printf("%lld\n", g);
	}
	return 0;
}
