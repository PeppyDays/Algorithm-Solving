#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MaxN 100

int n;
bool adj[MaxN][MaxN];

int main() {
    ios_base::sync_with_stdio(false);

    memset(adj, 0, sizeof(adj));

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    for (int k = 0; k < n; ++k) {
        for (int u = 0; u < n; ++u) {
            if (!adj[u][k])
                continue;

            for (int v = 0; v < n; ++v) {
                if (!adj[k][v])
                    continue;

                if (adj[u][k] && adj[k][v])
                    adj[u][v] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}

