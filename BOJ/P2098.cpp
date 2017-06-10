#include <cstdio>
using namespace std;

const int INF = ~(1 << 31);
const int MaxN = 16;

int N;
int adj[MaxN + 1][MaxN + 1];
int cache[MaxN + 1][1 << (MaxN + 1)];
int allVisited;

int min(int x, int y);
int findPath(int here, int visited);

int main() {
    freopen("resources/input.in", "r", stdin);

    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            scanf("%d", &adj[i][j]);

    allVisited = (1 << (N + 1)) - 2;

    for (int i = 1; i <= N; ++i)
        for (int j = 0; j <= allVisited; ++j)
            cache[i][j] = -2;

    int ret = findPath(1, 0);
    printf("%d\n", ret);

    return 0;
}

int min(int x, int y) {
    return x < y ? x : y;
}

int findPath(int here, int visited) {
    if (visited == (allVisited - (1 << here))) {
        if (adj[here][1])
            return adj[here][1];
        else
            return -1;
    }

    if (cache[here][visited] != -2)
        return cache[here][visited];

    int& ret = cache[here][visited];
    ret = INF;

    visited |= (1 << here);

    for (int there = 1; there <= N; ++there) {
        if (!adj[here][there] || (visited & (1 << there)))
            continue;

        int subRet = findPath(there, visited);
        if (subRet == -1)
            continue;

        ret = min(ret, subRet + adj[here][there]);
    }

    if (ret == INF)
        ret = -1;

    visited &= ~(1 << here);
    return ret;
}