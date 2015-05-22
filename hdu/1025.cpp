//Url:http://acm.hdu.edu.cn/showproblem.php?pid=1025

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 500010
struct PR {
    int  p;
    int  r;
}pr[MAX];
int marray[MAX];

typedef struct PR PR;

int cmp(const void *e1, const void *e2)
{
    return ((PR*)e1)->p - ((PR*)e2)->p;
}

int DP_OPT(PR *a, int len)
{ //O(nlogn)
    int lis = 0;
    marray[0] = a[0].r;

    for (int i=1; i<len; ++i)
    {
        //二分查找
        int  s=0, e=lis;
        if (marray[lis] < a[i].r)
        {
            marray[lis+1] = a[i].r;
            ++lis;
        }
        else
        {
            while (s <= e)
            {
                int mid = (s+e) >> 1;
                if (a[i].r > marray[mid]) s = mid + 1;
                else e = mid - 1;
            }
            marray[s] = a[i].r;
        }
    }
    return lis+1;
}
int main()
{
    freopen("testdata/1025.in", "r", stdin);

    int t, c=0;
    while (scanf("%d", &t) != EOF)
    {
        memset(pr, 0, sizeof(pr));
        for (int i=0; i<t; ++i) scanf("%d %d", &pr[i].p, &pr[i].r);

        qsort(&pr[0], t, sizeof(PR), &cmp);

        int len = DP_OPT(&pr[0], t);

        if (len > 1) printf("Case %d:\nMy king, at most %d roads can be built.\n\n", ++c, len);
        else printf("Case %d:\nMy king, at most %d road can be built.\n\n", ++c, len);
    }
    return 0;
}
