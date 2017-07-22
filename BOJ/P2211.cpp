#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent;
vector<int> depth;
vector<pair<int, pair<int, int> > > adj;
vector<int> answer;

int find(int u) {
    if (parent[u] == -1)
        return u;

    return parent[u] = find(parent[u]);
};

void merge(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
        return;

    if (depth[u] > depth[v])
        swap(u, v);

    parent[u] = v;

    if (depth[u] == depth[v])
        ++depth[v];
}

int main() {
    freopen("resources/input.in", "r", stdin);

    int N, M;
    scanf("%d %d", &N, &M);
    parent.resize(N, -1);
    depth.resize(N, 0);
    adj.resize(M);

    int u, v, c;
    for (int i = 0; i < M; ++i) {
        scanf("%d %d %d", &u, &v, &c);
        adj[i] = make_pair(c, make_pair(u, v));
    }

    sort(adj.begin(), adj.end());

    printf("%d\n", N - 1);
    for (int i = 0; i < M; ++i) {
        u = adj[i].second.first;
        v = adj[i].second.second;

        if (find(u) == find(v))
            continue;

        merge(u, v);
        printf("%d %d\n", u, v);
    }

    return 0;
}