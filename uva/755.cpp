//Url:http://uva.onlinejudge.org/external/7/755.pdf

#include <iostream>
#include <map>
#include <string>
#include <cstdio>
#include <cctype>

using namespace std;

int table[90];

void init()
{
    table[48] = 0 + '0';
    table[49] = 1 + '0';
    table[50] = 2 + '0';
    table[51] = 3 + '0';
    table[52] = 4 + '0';
    table[53] = 5 + '0';
    table[54] = 6 + '0';
    table[55] = 7 + '0';
    table[56] = 8 + '0';
    table[57] = 9 + '0';

    table[65] = 2 + '0';
    table[66] = 2 + '0';
    table[67] = 2 + '0';

    table[68] = 3 + '0';
    table[69] = 3 + '0';
    table[70] = 3 + '0';

    table[71] = 4 + '0';
    table[72] = 4 + '0';
    table[73] = 4 + '0';

    table[74] = 5 + '0';
    table[75] = 5 + '0';
    table[76] = 5 + '0';

    table[77] = 6 + '0';
    table[78] = 6 + '0';
    table[79] = 6 + '0';

    table[80] = 7 + '0';
    table[82] = 7 + '0';
    table[83] = 7 + '0';

    table[84] = 8 + '0';
    table[85] = 8 + '0';
    table[86] = 8 + '0';

    table[87] = 9 + '0';
    table[88] = 9 + '0';
    table[89] = 9 + '0';
}

int main()
{
    freopen("testdata/755.in", "r", stdin);
    int  t, l;
    int f = 1;
    string  s, tmp(8, '-');
    map<string, int> mmap;
    scanf("%d", &t);
    getchar(); getchar();
    init();
    while (t--)
    {
        if (f) f=0;
        else cout << endl;
        scanf("%d\n", &l);
        while (l--)
        {
            cin >> s;
            int k = 0;
            for (int i=0; i<s.size(); ++i)
            {
                if (isalnum(s[i]))
                    tmp[k++] = table[s[i]];
                if (k==3)
                    ++k;
            }
            if (! mmap.count(tmp)) mmap[tmp] = 1;
            else mmap[tmp]++;
        }
        int flag = 1;
        for (map<string,int>::iterator it=mmap.begin();
                it != mmap.end();
                it++)
            if (it->second >= 2)
            {
                flag = 0;
                printf("%s %d\n", it->first.c_str(), it->second);
            }
        if (flag)
            cout << "No duplicates." << endl;
        mmap.clear();
        getchar();
        getchar();
    }
        
    return 0;
}
