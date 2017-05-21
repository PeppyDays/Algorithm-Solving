#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> couple;
const int MaxV = 100001;

int V, E, counter = 1;
vector<int> adj[MaxV];
int discovered[MaxV];
vector<couple> cutEdge;

int findCutEdge(int here, int parent);

int main() {
    freopen("/Users/Donald/Documents/Algorithm-Solving/resources/input.in", "r", stdin);

    scanf("%d %d", &V, &E);

    int u, v;
    for (int i = 0; i < E; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start = 1, parent = 0;
    findCutEdge(start, parent);
    sort(cutEdge.begin(), cutEdge.end());

    printf("%lu\n", cutEdge.size());
    for (vector<couple>::iterator it = cutEdge.begin(), end = cutEdge.end(); it != end; ++it)
        printf("%d %d\n", it -> first, it -> second);

    return 0;
}

int findCutEdge(int here, int parent) {
    discovered[here] = counter++;
    int ret = discovered[here];

    for (int i = 0; i < adj[here].size(); ++i) {
        int there = adj[here][i];

        if (there == parent)
            continue;
        
        if (discovered[there] == 0) {
            int subRet = findCutEdge(there, here);

            if (subRet > discovered[here])
                cutEdge.push_back(make_pair(min(here, there), max(here, there)));
            
            ret = min(ret, subRet);
        }
        else {
            ret = min(ret, discovered[there]);
        }
    }

    return ret;
}
