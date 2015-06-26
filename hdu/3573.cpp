#include <cstdio>

using namespace std;

int main()
{
    freopen("testdata/3573.txt", "r", stdin);
    
    int t, a, b, c;
    int num, ca=1, tmp;
    scanf("%d", &t);
    while (t--) {
        num = 0;
        scanf("%d %d %d", &a, &b, &c);
        while (a>=2 && c>=1) {
            a -= 2;
            c -= 1;
            num++;
        }
        
        while (a>=2 && b>=1) {
            a -= 2;
            b -= 1;
            num++;
        }
        
        if (a == 0) {
            num += (b+c)/2 + (b+c)%2;
        }
        else if (a == 1) {
            num += (b+c)/2 + 1;
        }
        else if (a > 1) {
            num += a/3 + (a%3 ? 1 : 0);
        }
        
        printf("Case %d: %d\n", ca++, num);
    }
    
    return 0;
}