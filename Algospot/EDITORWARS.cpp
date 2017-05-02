#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MaxN = 10000;

int N, M;
int parent[MaxN], depth[MaxN], enemy[MaxN], size[MaxN];

int find(int u);
int merge(int u, int v);
bool dis(int u, int v);
bool ack(int u, int v);

int main() {
    freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/input.in", "r", stdin);

    int C;
    scanf("%d", &C);

    while (C--) {
        scanf("%d %d", &N, &M);

        memset(enemy, -1, sizeof(enemy));
        memset(depth, 0, sizeof(depth));
        for (int i = 0; i < N; ++i) {
            parent[i] = i;
            size[i] = 1;
        }

        bool hasContradiction = false;
        int hasContradictionIdx = -1;

        for (int q = 1; q <= M; ++q) {
            int u, v;
            char buf[4];
            scanf("%s %d %d", buf, &u, &v);

            if (hasContradiction)
                continue;

            if (buf[0] == 'A')
                hasContradiction = !ack(u, v);
            else
                hasContradiction = !dis(u, v);

            if (hasContradiction)
                hasContradictionIdx = q;
        }

        if (hasContradiction)
            printf("CONTRADICTION AT %d\n", hasContradictionIdx);
        else {
            int ret = -1;
            for (int i = 0; i < N; ++i)
                ret = max(ret, size[i]);

            for (int i = 0; i < N; ++i)
                if (parent[i] == i && size[i] == 1)
                    ++ret;

            printf("MAX PARTY SIZE IS %d\n", ret);
        }
    }

    return 0;
}

bool dis(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
        return false;

    int x = merge(u, enemy[v]);
    int y = merge(v, enemy[u]);
    enemy[x] = y;
    enemy[y] = x;

    return true;
}

bool ack(int u, int v) {
    u = find(u);
    v = find(v);

    if (enemy[u] == v || enemy[v] == u)
        return false;

    int x = merge(u, v);
    int y = merge(enemy[u], enemy[v]);
    enemy[x] = y;
    if (y != -1)
        enemy[y] = x;

    return true;
}

int find(int u) {
    if (u == parent[u])
        return u;

    return parent[u] = find(parent[u]);
}

int merge(int u, int v) {
    if (u == -1 || v == -1)
        return max(u, v);

    u = find(u);
    v = find(v);

    if (u == v)
        return u;

    if (depth[u] > depth[v])
        swap(u, v);

    if (depth[u] == depth[v])
        depth[v]++;

    parent[u] = v;
    size[v] += size[u];

    return v;
}
