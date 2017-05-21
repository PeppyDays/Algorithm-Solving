#include <iostream>
#include <vector>
using namespace std;

void dfs(int here, int& counter, vector<vector<int> >& adj, vector<int>& discovered, vector<bool>& finished);

int main() {
    ios_base::sync_with_stdio(false);
    freopen("/Users/Donald/Documents/Algorithm-Solving/resources/input.in", "r", stdin);

    int n, e, counter = 1;
    cin >> n >> e;

    vector<vector<int> > adj(n);
    vector<int> discovered(n);
    vector<bool> finished(n);

    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int start = 0;
    dfs(start, counter, adj, discovered, finished);

    return 0;
}

void dfs(int here, int& counter, vector<vector<int> >& adj, vector<int>& discovered, vector<bool>& finished) {
    discovered[here] = counter++;

    for (int i = 0; i < adj[here].size(); ++i) {
        int there = adj[here][i];
        cout << "(" << here << ", " << there << "): ";

        if (discovered[there] == 0) {
            cout << "tree edge" << '\n';
            dfs(there, counter, adj, discovered, finished);
        }
        else if (discovered[here] < discovered[there]) {
            cout << "forward edge" << '\n';
        }
        else if (!finished[there]) {
            cout << "back edge" << '\n';
        }
        else {
            cout << "cross edge" << '\n';
        }
    }

    finished[here] = true;
}
