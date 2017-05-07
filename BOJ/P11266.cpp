#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MaxV = 10001;

int V, E, counter = 1, cutVertexCnt = 0;
vector<int> adj[MaxV];
int discovered[MaxV];
bool isCutVertex[MaxV];

int dfs(int here, bool isRoot);

int main() {
    freopen("/Users/Donald/Documents/Algorithm-Solving/resources/input.in", "r", stdin);

    scanf("%d %d", &V, &E);

    int u, v;
    for (int i = 0; i < E; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= V; ++i) {
        if (discovered[i] == 0)
            dfs(i, true);
    }

    printf("%d\n", cutVertexCnt);
    for (int i = 1; i <= V; ++i) {
        if (isCutVertex[i])
            printf("%d ", i);
    }

    return 0;
}

int dfs(int here, bool isRoot) {
    discovered[here] = counter++;
    int ret = discovered[here];
    int childCnt = 0;

    for (int i = 0; i < adj[here].size(); ++i) {
        int there = adj[here][i];

        if (discovered[there] == 0) {
            childCnt++;
            int subRet = dfs(there, false);
            ret = min(ret, subRet);

            if (!isRoot && !isCutVertex[here] && subRet >= discovered[here]) {
                cutVertexCnt++;
                isCutVertex[here] = true;
            }
        }
        else {
            ret = min(ret, discovered[there]);
        }
    }

    if (isRoot && childCnt >= 2) {
        cutVertexCnt++;
        isCutVertex[here] = true;
    }

    return ret;
}
