#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, pair<int, int> > couple;
const int MaxN = 1000, MaxM = 100000;

int N, M;
couple edge[MaxM];

int parent[MaxN];
int depth[MaxN];

int find(int u);
void merge(int u, int v);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    int u, v, c;

    for (int i = 0; i < M; ++i) {
        cin >> u >> v >> c;
        edge[i] = make_pair(c, make_pair(u - 1, v - 1));
    }

    for (int i = 0; i < N; ++i) {
        parent[i] = i;
        depth[i] = 1;
    }

    sort(edge, edge + M);

    int cntSelected = 0, costSelected = 0;

    for (int i = 0; i < M; ++i) {
        c = edge[i].first, u = edge[i].second.first, v = edge[i].second.second;
        u = find(u);
        v = find(v);

        if (u == v)
            continue;

        merge(u, v);
        cntSelected += 1;
        costSelected += c;

        if (cntSelected == N - 1)
            break;
    }

    cout << costSelected << '\n';

    return 0;
}

int find(int u) {
    if (parent[u] == u)
        return u;

    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
        return;

    if (depth[u] < depth[v])
        parent[u] = v;
    else
        parent[v] = u;

    if (depth[u] == depth[v])
        ++depth[u];
}
