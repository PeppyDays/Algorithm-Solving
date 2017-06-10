#include <cstdio>
#include <algorithm>
using namespace std;

char in[10000000];
const char* o;

void getIn() {
    o = in;
    in[fread(in, 1, sizeof(in) - 4, stdin)] = '\n';
}

int nextInt() {
    int ret = 0;
    bool sign = true;

    while (*o < '0' || *o > '9') ++o;
    while (*o >= '0' && *o <= '9') ret = 10 * ret + *o++ - '0';

    return ret;
}

typedef pair<int, pair<int, int> > couple;
const int MaxN = 1000, MaxM = 100000;

int N, M;
couple edge[MaxM];

int parent[MaxN];
int depth[MaxN];

int find(int u);
void merge(int u, int v);

int main() {
<<<<<<< HEAD
    freopen("resources/input.in", "r", stdin);
=======
>>>>>>> ecd03fb8e38cb385f61717f4df26389359fb85d9
    getIn();

    N = nextInt();
    M = nextInt();

    int u, v, c;
    for (int i = 0; i < M; ++i) {
        u = nextInt();
        v = nextInt();
        c = nextInt();
        edge[i] = make_pair(c, make_pair(u - 1, v - 1));
    }

    for (int i = 0; i < N; ++i) {
        parent[i] = i;
        depth[i] = 1;
    }

    sort(edge, edge + M);

    int cntMergeNode = 1;
    int costLine = 0;

    for (int i = 0; i < M; ++i) {
        c = edge[i].first, u = edge[i].second.first, v = edge[i].second.second;
        u = find(u);
        v = find(v);

        if (u == v)
            continue;

        merge(u, v);
        cntMergeNode += 1;
        costLine += c;

        if (cntMergeNode == N)
            break;
    }

    printf("%d\n", costLine);

    return 0;
}

int find(int u) {
    if (parent[u] == u)
        return u;

    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
        return;

    if (depth[u] < depth[v])
        parent[u] = v;
    else
        parent[v] = u;

    if (depth[u] == depth[v])
        ++depth[u];
}

