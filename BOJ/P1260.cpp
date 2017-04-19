#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define MaxN 1001
#define MaxM 10001

int N, M, start;
bool Map[MaxN][MaxN];
bool visited[MaxN];

void dfs(int here);
void bfs(int start);

int main() {
    ios_base::sync_with_stdio(false);

    memset(Map, 0, sizeof(Map));

    cin >> N >> M >> start;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        Map[u][v] = true;
        Map[v][u] = true;
    }

    // DFS
    memset(visited, 0, sizeof(visited));
    dfs(start);
    cout << '\n';

    // BFS
    memset(visited, 0, sizeof(visited));
    bfs(start);
    cout << '\n';

    return 0;
}

void dfs(int here) {
    visited[here] = true;
    cout << here << ' ';

    for (int there = 1; there <= N; ++there) {
        if (Map[here][there] && !visited[there])
            dfs(there);
    }
}

void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);
    cout << start << ' ';

    while (!q.empty()) {
        int here = q.front();
        q.pop();

        for (int there = 1; there <= N; ++there) {
            if (Map[here][there] && !visited[there]) {
                visited[there] = true;
                q.push(there);
                cout << there << ' ';
            }
        }
    }
}
