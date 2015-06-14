#include <iostream>
#include <cstdio>
#define MMAX 10000 + 10
using namespace std;

int main()
{
    freopen("testdata/3485.txt", "r", stdin);
    int ans[MMAX] = {0, 2, 4, 7};
	int  n;
    for (int i=4; i<MMAX; ++i) {
        ans[i] = (2*ans[i-1] - (ans[i-2] - ans[i-3])) % 9997;
    }
	while (cin >> n) {
		if (n == -1) break;
        cout << ans[n] << endl;
	}
}
