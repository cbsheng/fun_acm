#include <iostream>
#include <cstdio>

#define MAX 100000

using namespace std;

int  seq[MAX + 10];
int  tmp_seq[MAX + 10];
int  pos[MAX + 10];

int max_subarray(int *seq, int n)
{
    tmp_seq[1] = seq[1];
    pos[1] = 1;
    int  mmax = tmp_seq[1];
    for (int i=2; i<=n; ++i)
    {
        int tmp = tmp_seq[i-1]+seq[i];
        if (tmp >= seq[i])
        {
            tmp_seq[i] = tmp;
            pos[i] = pos[i-1];
        }
        else
        {
            tmp_seq[i] = seq[i];
            pos[i] = i;
        }
        if (mmax < tmp_seq[i]) mmax = tmp_seq[i];
    }
    return mmax;
}

int main()
{
    //freopen("testdata/1003.txt", "r", stdin);
    int t;
    int Case = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i=1; i<=n; ++i) cin >> seq[i];
        int sum = max_subarray(seq, n);
        int e=0;
        for (int i=1; i<=n; ++i)
        {
            if (tmp_seq[i] == sum)
            {
                e = i;
                break;
            }
        }
        printf("Case %d:\n", Case++);
        printf("%d %d %d\n", sum, pos[e], e);
        if (t!=0) cout << endl;
    }
    return 0;
}
