//Url:http://uva.onlinejudge.org/external/103/10361.pdf

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    freopen("testdata/10361.in", "r", stdin);
    string l1, l2;
    string s2, s3, s4, s5;
    string::size_type f1, e1, f2, e2;
    int  i;
    char c;
    cin >> i;
    cin.get();
    while (i--)
    {
        getline(cin, l1);
        getline(cin, l2);
        cout << "---- " << l1 << endl;
        cout << "---- " << l2 << endl;
        f1 = l1.find("<", 0);
        e1 = l1.find(">", f1);
        f2 = l1.find("<", e1);
        e2 = l1.find(">", f2);

        s2 = l1.substr(f1+1, e1-f1-1);
        s3 = l1.substr(e1+1, f2-e1-1);
        s4 = l1.substr(f2+1, e2-f2-1);
        s5 = l1.substr(e2+1, l1.size()-e2-1);
        
        cout << l1.substr(0, f1) << s2 << s3 << s4 << s5 << endl;
        cout << l2.substr(0, l2.find("...", 0)) << s4 << s3 << s2 << s5 << endl;
    }
    fclose(stdin);
    return 0;
}
