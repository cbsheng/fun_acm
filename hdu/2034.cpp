#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;


int main ()
{
        vector<int>    a, b;
        int            n, m;
        int               input;
        while (scanf("%d %d%*c", &n, &m), n | m)
        {
            a.clear();
            b.clear();
            for (int i = 0; i < n; i++)
            {
                cin >> input;
                a.push_back(input);
            }    
            for (int i = 0; i < m; i++)
            {
                cin >> input;
                b.push_back(input);
            }    
            sort(a.begin(), a.end());
            vector<int>::iterator  iter = a.begin();
            vector<int>::iterator  iter1;
            while (iter != a.end())
            {
                iter1 = find(b.begin(), b.end(), *iter);
                if (iter1 != b.end())
                {
                    iter = a.erase(iter);
                }
                else
                {
                    iter++;
                }
            }
            if (a.size() == 0)
            {
                cout << "NULL\n";
                continue;
            }
            for (iter = a.begin(); iter != a.end(); iter++)
            {
                cout << *iter << " ";
            }
            cout << endl;
        }
        return    0;
}