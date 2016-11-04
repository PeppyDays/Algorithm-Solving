#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int n, m, start;

class compByDist {
public:
    bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    vector<vector<pair<int, int> > > graph(n + 1);

    cin >> start;

    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, compByDist> pq;
    vector<int> dist(n + 1, -1);

    dist[start] = 0;
    pq.push(make_pair(start, 0));

    while (!pq.empty()) {
        int here = pq.top().first;
        int distStartToHere = pq.top().second;
        pq.pop();

        if (distStartToHere > dist[here])
            continue;

        for (int i = 0; i < graph[here].size(); ++i) {
            int there = graph[here][i].first;
            int distHereToThere = graph[here][i].second;

            if (dist[there] == -1 || distStartToHere + distHereToThere < dist[there]) {
                dist[there] = distStartToHere + distHereToThere;
                pq.push(make_pair(there, dist[there]));
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (dist[i] != -1)
            printf("%d\n", dist[i]);
        else
            printf("INF\n");
    }

    return 0;
}

