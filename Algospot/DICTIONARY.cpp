#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, C;
vector<string> Words;
vector<int> Adj[26];
int inAdj[26];
vector<int> Order;

int main() {
    ios_base::sync_with_stdio(false);
    freopen("/Users/Donald/Documents/Algorithm-Solving/resources/input.in", "r", stdin);

    cin >> C;
    while (C--) {
        cin >> N;
        Words.resize(N);
        Order.clear();
        memset(inAdj, 0, sizeof(inAdj));
        for (int i = 0; i < 26; ++i) Adj[i].clear();

        for (int i = 0; i < N; ++i)
            cin >> Words[i];

        for (int aIdx = 1; aIdx < N; ++aIdx) {
            int bIdx = aIdx - 1;
            int wIdx = 0;

            while (Words[aIdx][wIdx] == Words[bIdx][wIdx])
                ++wIdx;
            
            int u = Words[bIdx][wIdx] - 'a';
            int v = Words[aIdx][wIdx] - 'a';
            Adj[u].push_back(v);
            inAdj[v]++;
        }

        queue<int> q;
        for (int i = 0; i < 26; ++i)
            if (inAdj[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int here = q.front();
            Order.push_back(here);
            q.pop();

            for (vector<int>::iterator it = Adj[here].begin(), end = Adj[here].end(); it != end; ++it) {
                int there = *it;
                inAdj[there]--;
                if (inAdj[there] == 0)
                    q.push(there);
            }
        }

        if (Order.size() != 26)
            cout << "INVALID HYPOTHESIS" << '\n';
        else {
            for (int i = 0; i < Order.size(); ++i) {
                char x = char(Order[i] + 'a');
                cout << x;
            }
            cout << '\n';
        }
    }

    return 0;
}