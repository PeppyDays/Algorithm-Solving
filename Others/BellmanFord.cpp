#include <cstdio>
#include <vector>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();
const int MaxV = 10000;

int V;

vector<pair<int, int> > adj[MaxV];

vector<int> bellmanFord(int start);

int main() {


    return 0;
}

vector<int> bellmanFord(int start) {
    vector<int> upper(V, INF);
    upper[start] = 0;
    bool updated;

    for (int iter = 0; iter < V; ++iter) {
        updated = false;
        for (int here = 0; here < V; ++here) {
            for (int i = 0; i < adj[here].size(); ++i) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;

                if (upper[there] > upper[here] + cost) {
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }
        }

        if (!updated)
            break;
    }

    if (updated)
        return upper.clear();

    return upper;
}