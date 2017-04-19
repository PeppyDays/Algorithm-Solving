#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

typedef pair<int, int> couple;
const int MaxN = 301;

int n, m, k;
map<int, int> adj[MaxN];
int cache[MaxN][MaxN];

int score(int s, int l);

int main() {
    memset(cache, -1, sizeof(cache));

    scanf("%d %d %d", &n, &m, &k);
    int u, v, c;
    for (int i = 0; i < k; ++i) {
        scanf("%d %d %d", &u, &v, &c);

        if (u >= v)
            continue;

        if (adj[u].find(v) == adj[u].end())
            adj[u][v] = c;
        else
            adj[u][v] = max(adj[u][v], c);
    }

    printf("%d\n", score(1, m));

    return 0;
}

int score(int s, int l) {
    if (s == n && l >= 1)
        return 0;

    if (s == n || l == 1)
        return -1;

    int& ret = cache[s][l];
    if (ret != -1)
        return ret;

    for (map<int, int>::iterator it = adj[s].begin(), end = adj[s].end(); it != adj[s].end(); ++it) {
        int next = it->first;
        int scoreToNext = it->second;
        int scoreToDest = score(next, l - 1);
        if (scoreToDest == -1)
            continue;
        ret = max(ret, scoreToNext + scoreToDest);
    }

    return ret;
}
