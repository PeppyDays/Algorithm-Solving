#include <cstdio>
#include <vector>
#include <cstring>
#include <limits>
using namespace std;

char in[1 << 20];
const char* o;

void getIn() {
    o = in;
    in[fread(in, 1, sizeof(in) - 4, stdin)] = '\n';
}

int nextInt() {
    int ret = 0;
    bool sign = true;

    while ((*o < '0' || *o > '9') && *o != '-') ++o;
    if (*o == '-') { sign = false; o++; };
    while (*o >= '0' && *o <= '9') ret = 10 * ret + *o++ - '0';

    return sign ? ret : -ret;
}

typedef pair<int, int> couple;

const int INF = numeric_limits<int>::max();
const int MaxN = 501;

int N, M;
vector<couple> adj[MaxN];
int dist[MaxN];

int main() {
    freopen("resources/input.in", "r", stdin);
    getIn();

    N = nextInt();
    M = nextInt();

    int u, v, c;
    for (int i = 1; i <= M; ++i) {
        u = nextInt();
        v = nextInt();
        c = nextInt();

        adj[u].push_back(make_pair(v, c));
    }

    for (int i = 1; i <= N; ++i)
        dist[i] = INF;

    dist[1] = 0;
    bool updated;

    for (int t = 0; t < N; ++t) {
        updated = false;

        for (int here = 1; here <= N; ++here) {
            int distHere = dist[here];

            if (distHere == INF)
                continue;

            for (int i = 0; i < adj[here].size(); ++i) {
                int there = adj[here][i].first;
                int distHereToThere = adj[here][i].second;

                if (distHere + distHereToThere < dist[there]) {
                    dist[there] = distHere + distHereToThere;
                    updated = true;
                }
            }
        }

        if (!updated)
            break;
    }

    if (updated)
        printf("%d\n", -1);
    else {
        for (int i = 2; i <= N; ++i)
            printf("%d\n", dist[i] == INF? -1 : dist[i]);
    }

    return 0;
}