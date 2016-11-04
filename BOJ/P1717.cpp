#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define MaxN 1000001

int n, m;
int parent[MaxN];
int depth[MaxN];
map<int, vector<int> > adj;

int find(int u);
void merge(int u, int v);

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    // scanf("%d %d", &n, &m);

    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
        depth[i] = 1;
    }

    int op, u, v;
    for (int i = 0; i < m; ++i) {
        cin >> op >> u >> v;
        // scanf("%d %d %d", &op, &u, &v);

        if (op == 0) {
            merge(u, v);
        }
        else if (op == 1) {
            if (find(u) == find(v))
                // cout << "YES" << '\n';
                printf("YES\n");
            else
                // cout << "NO" << '\n';
                printf("NO\n");
        }
    }

    return 0;
}

int find(int u) {
    if (u == parent[u])
        return u;

    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    int uRoot = find(u);
    int vRoot = find(v);

    if (uRoot == vRoot)
        return;

    if (depth[uRoot] > depth[vRoot])
        swap(uRoot, vRoot);

    parent[uRoot] = vRoot;

    if (depth[uRoot] == depth[vRoot])
        ++depth[vRoot];
}
