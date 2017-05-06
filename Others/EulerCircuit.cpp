#include <iostream>
#include <vector>
using namespace std;

// Sample input
// 8 9
// 0 1
// 1 2
// 2 3
// 3 4
// 4 0
// 3 5
// 5 6
// 6 7
// 7 3

typedef pair<int, bool> couple;

void getEulerCircuit(int here, vector<vector<couple> >& adj, vector<int>& circuit);

int main() {
    ios_base::sync_with_stdio(false);
    freopen("/Users/Donald/Documents/Algorithm-Solving/resources/input.in", "r", stdin);

    int n, m, u, v;
    vector<vector<couple> > adj;
    vector<int> circuit;

    cin >> n >> m;
    adj.resize(n);

    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(make_pair(v, true));
    }

    getEulerCircuit(0, adj, circuit);
    reverse(circuit.begin(), circuit.end());
    
    for (int i = 0; i < circuit.size(); ++i)
        cout << circuit[i] << ' ';

    return 0;
}

void getEulerCircuit(int here, vector<vector<couple> >& adj, vector<int>& circuit) {
    for (vector<couple>::iterator it = adj[here].begin(), end = adj[here].end(); it != end; ++it) {
        if (it -> second) {
            it -> second = false;
            getEulerCircuit(it -> first, adj, circuit);
        }
    }

    circuit.push_back(here);
}