//用 dfs 解决。参《算法导论》22章，用白、灰、黑三色标示，dfs 过程中遇到灰色则说明有环
#include <vector>
#include <cstdio>
#include <map>
#include <iostream>
#include <set>
#include <cstring>

using namespace std;
#define MMAX 100

int color[MMAX + 10]; //1是灰色，0是白色，2是黑色

map<int, vector<int> > mmap;
int dfs(map<int, vector<int> > &mmap, int ma)
{
    int ok = 1;
    color[ma] = 1;
    if (0 == mmap.count(ma)) {
        color[ma] = 2;
        return 1;
    }
    vector<int> prs = mmap[ma];
    for (int i=0; i<prs.size(); ++i) {
        if (0 == color[prs[i]]) {
            ok = dfs(mmap, prs[i]);
            if (!ok) break;
        }
        if (1 == color[prs[i]]) {
            ok = 0;
            break;
        }
    }
    color[ma] = 2;
    return ok;
}

int main()
{
    freopen("testdata/3342.txt", "r", stdin);
    int N, M;
    int ma, pr;
    while (cin >> N >> M) {
        if (0 == N) break;
        for (int i=0; i<M; ++i) {
            cin >> ma >> pr;
            if (0 == mmap.count(ma)) {
                vector<int> prs;
                prs.push_back(pr);
                mmap[ma] = prs;
            }
            else {
                mmap[ma].push_back(pr);
            }
        }
        memset(color, 0, sizeof(color));
        int ok;
        for (map<int, vector<int> >::iterator it = mmap.begin();
                it != mmap.end();
                ++it) {
                    if (0 == color[it->first]) {
                        ok = dfs(mmap, it->first);
                        if (ok == 0) break;
                    }
                }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
        mmap.clear();
    }
    return 0;
}
