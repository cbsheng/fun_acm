//Url:http://uva.onlinejudge.org/external/5/575.pdf

#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

char  input[32];
int main()
{
    freopen("testdata/575.in", "r", stdin);
    int  num;
    long res;
    while (scanf("%s", input) != EOF)
    {
        res = 0;
        num = 1;
        if (input[0] == '0') break;
        for (int j=strlen(input)-1; j >=0; --j)
        {
            if (input[j] != '0')
                res += (input[j] - '0') * ((int)pow(2, num) - 1);
            ++num;
        }
        printf("%ld\n", res);
    }
    return 0;
}
