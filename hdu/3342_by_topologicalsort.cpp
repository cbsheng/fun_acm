//用拓扑解决
#include <cstdio>
#include <cstring>

using namespace std;
#define MMAX 110

int N, M;
int edge[MMAX][MMAX]; //边
int in[MMAX]; //进度

int topo_sort()
{
    int n;
    for (int i = 0; i < N; ++i) {
        n = N;
        for (int j = 0; j < N; ++j) {
            if (in[j] == 0) {  //找出入度为0的
                in[j]--;
                n = j; //记录
                break;  
            }
        }
        if (n == N) //说明还在循环中，却找不到入度为0，说明有环
            return 0;
        for (int j = 0; j < N; ++j) {
            //将所有与 n 相连的结点的入度减一
            if (edge[n][j]) in[j]--;
        }
    }
    return 1;
}
int main()
{
    freopen("testdata/3342.txt", "r", stdin);
    int ma, pr;
    while (scanf("%d %d", &N, &M), N&&M) {
        memset(edge, 0, sizeof(edge));
        memset(in, 0, sizeof(in));
        for (int i = 0; i < M; ++i) {
            scanf("%d %d", &ma, &pr);
            if (! edge[ma][pr]) in[pr]++;
            edge[ma][pr] = 1;
        }
        
        if (topo_sort()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
