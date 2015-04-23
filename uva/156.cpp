//Url:http://uva.onlinejudge.org/external/1/156.pdf

#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    freopen("testdata/156.in", "r", stdin);
    string  s;
    map<string, pair<string, int> > mmap;
    pair<string, int> tmp;
    while (cin >> s)
    {
        if (s[0] == '#')
            break;
        string lower_s(s);
        transform(s.begin(), s.end(), lower_s.begin(), ::tolower);
        sort(lower_s.begin(), lower_s.end());
        
        if (! mmap.count(lower_s))
        {
            tmp = make_pair(s, 1);
            mmap[lower_s] = tmp;
        }
        else
            mmap[lower_s].second++;
    }
    map<string, int> res;
    for (map<string, pair<string, int> >::iterator it=mmap.begin();
            it!=mmap.end();
            ++it)
        if (it->second.second == 1)
            res[it->second.first] = 1;
    for (map<string, int>::iterator it=res.begin();
            it!=res.end();
            ++it)
        cout << it->first << endl;
    return 0;
}
