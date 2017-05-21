#include <cstdio>
#include <vector>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();
const int MaxV = 10000;

int V;
vector<pair<int, int> > adj[MaxV];

vector<int> bellmanFord(int start) {
    vector<int> dist(V, INF);
    dist[start] = 0;
    bool updated;

    for (int iter = 0; iter < V; ++iter) {
        updated = false;

        for (int here = 0; here < V; ++here) {

            if (dist[here] == INF)
                continue;

            for (int i = 0; i < adj[here].size(); ++i) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;

                if (dist[there] > dist[here] + cost) {
                    dist[there] = dist[here] + cost;
                    updated = true;
                }
            }
        }

        if (!updated)
            break;
    }

    if (updated)
        dist.clear();

    return dist;
}

int main() {

    return 0;
}