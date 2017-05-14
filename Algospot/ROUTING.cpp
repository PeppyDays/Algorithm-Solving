#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <limits>
using namespace std;

typedef pair<double, int> couple;

const double INF = numeric_limits<double>::max();
const int MaxN = 10000;

int N, M;
vector<couple> adj[MaxN];
double dist[MaxN];

int main() {
    freopen("resources/input.in", "r", stdin);

    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &N, &M);

        for (int i = 0; i < N; ++i) {
            adj[i].clear();
            dist[i] = INF;
        }

        for (int i = 0; i < M; ++i) {
            int u, v;
            double c;

            scanf("%d %d %lf", &u, &v, &c);
            adj[u].push_back(make_pair(c, v));
            adj[v].push_back(make_pair(c, u));
        }

        priority_queue<couple, vector<couple>, greater<couple> > pq;
        dist[0] = 1.0;
        pq.push(make_pair(1.0, 0));

        while (!pq.empty()) {
            int here = pq.top().second;
            double distHere = pq.top().first;
            pq.pop();

            if (distHere > dist[here])
                continue;

            if (here == N - 1)
                break;

            for (vector<couple>::iterator it = adj[here].begin(), end = adj[here].end(); it != end; ++it) {
                int there = it -> second;
                double distThere = distHere * it -> first;

                if (distThere < dist[there]) {
                    dist[there] = distThere;
                    pq.push(make_pair(distThere, there));
                }
            }
        }

        printf("%.10f\n", dist[N - 1]);
    }

    return 0;
}
