#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> couple;

int n, m, x;
vector<vector<couple> > map;
vector<int> distToX;
vector<int> distFromX;

class compByDist {
public:
    bool operator() (const couple& p1, const couple& p2) {
        return p1.second > p2.second;
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> x;

    map.resize(n + 1);

    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        map[u].push_back(couple(v, w));
    }

    distToX.resize(n + 1, -1);
    distFromX.resize(n + 1);

    for (int start = 1; start <= n; ++start) {
        priority_queue<couple, vector<couple>, compByDist> pq;
        vector<int> dist(n + 1, -1);

        dist[start] = 0;
        pq.push(couple(start, 0));

        while (!pq.empty()) {
            int here = pq.top().first;
            int distToHere = pq.top().second;
            pq.pop();

            if (distToHere > dist[here])
                continue;

            if (start != x && here == x)
                break;

            for (int thereIdx = 0; thereIdx < map[here].size(); ++thereIdx) {
                int there = map[here][thereIdx].first;
                int distHereToThere = map[here][thereIdx].second;

                if (dist[there] == -1 || distToHere + distHereToThere < dist[there]) {
                    dist[there] = distToHere + distHereToThere;
                    pq.push(couple(there, dist[there]));
                }
            }
        }

        if (start != x)
            distToX[start] = dist[x];
        else
            distFromX.assign(dist.begin(), dist.end());
    }

    int maxDist = -1;

    for (int i = 1; i <= n; ++i) {
        if (distToX[i] == -1 || distFromX[i] == -1)
            continue;

        if (distToX[i] + distFromX[i] > maxDist)
            maxDist = distToX[i] + distFromX[i];
    }

    cout << maxDist << '\n';

    return 0;
}

