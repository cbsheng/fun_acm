//Url:http://uva.onlinejudge.org/external/104/10494.pdf

#include <cstdio>
#include <iostream>
#include <cstring>

int main()
{
    freopen("testdata/10494.in", "r", stdin);
    char  f[2000], symbol;
    int   fac[2000];
    long long int s, rem;
    while (std::cin >> f >> symbol >> s)
    {
        rem = 0;
        long long int div;
        for (int i=0; i<strlen(f); ++i)
        {
            div = rem*10 + (f[i] - '0');
            fac[i] = div / s;
            rem = div % s;
        }
        if (symbol == '/')
        {
            int flag=0;
            for (int i=0; i<strlen(f); ++i)
            {
                if (fac[i] != 0)
                    flag = 1;
                if (flag)
                    printf("%d", fac[i]);
            }
            if (!flag)
                printf("0");
        }
        else
            printf("%lld", rem);
        puts("");

        
    }

    return 0;
}
