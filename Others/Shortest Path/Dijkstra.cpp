#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();
const int MaxN = 10000;
typedef pair<int, int> couple;

int N;
vector<couple> adj[MaxN];

vector<int> dijkstra(int start);

int main() {



    return 0;
}

vector<int> dijkstra(int start) {
    vector<int> dist(N, INF);
    priority_queue<couple, vector<couple>, greater<couple> > pq;

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int here = pq.top().second;
        int distHere = pq.top().first;
        pq.pop();

        if (distHere > dist[here])
            continue;

        for (vector<couple>::iterator it = adj[here].begin(), end = adj[here].end(); it != end; ++it) {
            int there = it -> first;
            int distThere = distHere + it -> second;

            if (distThere < dist[there]) {
                dist[there] = distThere;
                pq.push(make_pair(distThere, there));
            }
        }

    }

    return dist;
}