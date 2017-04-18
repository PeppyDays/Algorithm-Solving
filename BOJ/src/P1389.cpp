#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
using namespace std;

#define MaxN 100
const int INF = numeric_limits<int>::max();

int n, m;
int adj[MaxN][MaxN];

int main() {
    ios_base::sync_with_stdio(false);

    memset(adj, -1, sizeof(adj));

    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        u--; v--;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for (int i = 0; i < n; ++i)
        adj[i][i] = 0;

    for (int k = 0; k < n; ++k) {
        for (int u = 0; u < n; ++u) {
            if (adj[u][k] == -1)
                continue;

            for (int v = 0; v < n; ++v) {
                if (adj[k][v] == -1)
                    continue;

                if (adj[u][v] == -1)
                    adj[u][v] = adj[u][k] + adj[k][v];
                else
                    adj[u][v] = min(adj[u][v], adj[u][k] + adj[k][v]);
            }
        }
    }

    int minNo = -1;
    int minKebinNo = INF;

    for (int i = 0; i < n; ++i) {
        int KebinNo = 0;

        for (int j = 0; j < n; ++j) {
            if (i == j || adj[i][j] == -1)
                continue;

            KebinNo += adj[i][j];
        }

        if (KebinNo < minKebinNo) {
            minNo = i;
            minKebinNo = KebinNo;
        }
    }

    cout << minNo + 1 << '\n';

    return 0;
}

