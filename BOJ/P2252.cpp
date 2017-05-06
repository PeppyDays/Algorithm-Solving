#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

const int MaxN = 32001, MaxM = 100000;

int n, m, u, v;
vector<int> adj[MaxN];
int indegree[MaxN];

int main() {
    ios_base::sync_with_stdio(false);
    freopen("/Users/Donald/Documents/Algorithm-Solving/resources/input.in", "r", stdin);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        indegree[i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (indegree[i] == 0)
            q.push(i);
    
    while (!q.empty()) {
        int here = q.front();
        printf("%d ", here);
        q.pop();

        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i];
            indegree[there]--;
            if (indegree[there] == 0)
                q.push(there);
        }
    }

    return 0;
}