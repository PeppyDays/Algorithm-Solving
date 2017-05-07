#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int N, C;
vector<int> in;
map<vector<int>, int> dist;

void findDist(int n);
void normalize(vector<int>& x);

int main() {
    findDist(8);

    scanf("%d", &C);
    while (C--) {
        scanf("%d", &N);
        in.resize(N);
        for (int i = 0; i < N; ++i)
            scanf("%d", &in[i]);
        
        if (N == 1) {
            printf("%d\n", 0);
        }
        else {
            normalize(in);
            in.resize(8);
            for (int i = N; i < 8; i++)
                in[i] = i;
            printf("%d\n", dist[in]);
        }
    }

    return 0;
}

void findDist(int n) {
    queue<pair<vector<int>, int> > q;
    vector<int> start(n);
    for (int i = 0; i < n; ++i)
        start[i] = i;
    
    dist[start] = 0;
    q.push(make_pair(start, 0));

    while (!q.empty()) {
        vector<int> there = q.front().first;
        int costThere = q.front().second + 1;
        q.pop();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 2; j <= n; ++j) {
                reverse(there.begin() + i, there.begin() + j);

                if (dist.count(there) == 0) {
                    dist[there] = costThere;
                    q.push(make_pair(there, costThere));
                }

                reverse(there.begin() + i, there.begin() + j);
            }
        }
    }
}

void normalize(vector<int>& x) {
    vector<int> t(N);
    copy(x.begin(), x.end(), t.begin());
    sort(t.begin(), t.end());
    map<int, int> m;

    for (int i = 0; i < N; ++i)
        m[t[i]] = i;
    
    for (int i = 0; i < N; ++i)
        x[i] = m[x[i]];
}