#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int MaxN = 500;

int N;
int T[MaxN];
vector<int> G[MaxN];
int D[MaxN];
int M[MaxN];

int main() {
    freopen("/Users/Donald/Documents/Algorithm-Solving/resources/input.in", "r", stdin);

    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        G[i].clear();
        D[i] = 0;
    }

    for (int i = 0; i < N; ++i) {
        scanf("%d", T + i);

        int u;
        while (scanf("%d", &u)) {
            if (u == -1)
                break;
            
            D[i]++;
            G[u - 1].push_back(i);
        }
    }

    queue<int> q;
    for (int i = 0; i < N; ++i) {
        if (D[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int here = q.front();
        q.pop();

        for (int i = 0; i < G[here].size(); ++i) {
            int there = G[here][i];
            M[there] = max(M[there], M[here] + T[here]);
            D[there]--;
            if (D[there] == 0)
                q.push(there);
        }
    }

    for (int i = 0; i < N; ++i)
        printf("%d\n", M[i] + T[i]);

    return 0;
}