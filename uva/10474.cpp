//Url:http://uva.onlinejudge.org/external/104/10474.pdf

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    freopen("testdata/10474.in", "r", stdin);
    int  n, q;
    int  num=1;
    while (scanf("%d %d\n", &n, &q) != EOF)
    {
        if (!n && !q)
            break;
        cout << "CASE# " << num++ << ":" << endl;
        vector<int> nn;
        int  input;
        for (int i=0; i<n; i++)
        {
            cin >> input;
            nn.push_back(input);
        }
        sort(nn.begin(), nn.end());
        int flag;
        for (int i=0; i<q; ++i)
        {
            cin >> input;
            flag = 1;
            for (int j=0; j<nn.size(); ++j)
                if (nn[j] == input)
                {
                    flag = 0;
                    cout << input << " found at " << j+1 << endl;
                    break;
                }
            if (flag)
                cout << input << " not found" << endl;
        }
    }
    return 0;
}
