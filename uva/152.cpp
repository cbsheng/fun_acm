//Url:http://uva.onlinejudge.org/external/1/152.pdf

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

double dis(double x1, double y1, double z1, double x2, double y2, double z2)
{
    return sqrt( pow(x1-x2, 2) + pow(y1-y2, 2) + pow(z1-z2, 2) );
}

struct Point {
    double x;
    double y;
    double z;
};
int  res[10];

int main()
{
    freopen("testdata/152.in", "r", stdin);
    double x, y, z, min;
    int d;
    vector<struct Point> p;
    while (cin >> x >> y >> z)
    {
        if (!x && !y && !z) break;
        struct Point tmp = {x=x, y=y, z=z};
        p.push_back(tmp);
    }
    for (int i=0; i<p.size(); ++i)
    {
        min = 999999999999;
        for (int j=0; j<p.size(); ++j)
        {
            if (j == i)
                continue;
            d = dis(p[i].x, p[i].y, p[i].z, p[j].x, p[j].y, p[j].z);
            if (d < min)
                min = d;
        }
        if (min >=0 && min < 10)
            res[int(min)]++;
    }
    for (int i=0; i<10; ++i)
        printf("%4d", res[i]);
    cout << endl;
    return 0;
}
