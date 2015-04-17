//Url:http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=25148
#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstdlib>

using namespace std;

int main()
{
    freopen("testdata/10878.in", "r", stdin);
    bitset<8>  b;
    char c;
    int i=7;
    while (scanf("%c", &c) != EOF)
    {
        if (c == '.')
            continue;
        if (c == 'o')
            b[i--] = 1;
        else if (c == ' ')
            b[i--] = 0;
        if (i == -1)
        {
            i = 7;
            printf("%c", (int)b.to_ulong());
            getc(stdin);
        }
    }
    fclose(stdin);
    return 0;
}
