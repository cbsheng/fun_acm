//Url:http://uva.onlinejudge.org/external/104/10420.pdf

#include <iostream>
#include <map>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;

int main()
{
    freopen("testdata/10420.in", "r", stdin);
    int  n;
    map<string, int> mmap;
    string  line, c;
    cin >> n;
    getline(cin, line);
    while (n--)
    {
        getline(cin, line);
        stringstream ss(line);
        ss >> c;
        if (! mmap.count(c))
            mmap[c]=1;
        else
            mmap[c]++;
    }
    for (map<string, int>::iterator iter=mmap.begin(); iter!=mmap.end(); iter++)
        cout << iter->first << " " << iter->second << endl;
    return 0;
}
