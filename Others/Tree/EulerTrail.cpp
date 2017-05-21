#include <iostream>
#include <vector>
using namespace std;

// Sample input
// 8 8
// 0 1
// 1 2
// 2 3
// 3 4
// 3 5
// 5 6
// 6 7
// 7 3

typedef pair<int, bool> couple;

void getEulerTrail(int start, int end, vector<vector<couple> >& adj, vector<int>& trail);
void getEulerCircuit(int start, vector<vector<couple> >& adj, vector<int>& circuit);

int main() {
    ios_base::sync_with_stdio(false);
    freopen("/Users/Donald/Documents/Algorithm-Solving/resources/input.in", "r", stdin);

    int n, m, u, v;
    vector<vector<couple> > adj;
    vector<int> trail;
    vector<int> in, out;

    cin >> n >> m;
    adj.resize(n);
    in.resize(n);
    out.resize(n);

    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(make_pair(v, true));
        out[u]++;
        in[v]++;
    }

    int start, end;
    for (int i = 0; i < n; ++i) {
        if (in[i] == out[i])
            continue;
        
        if (in[i] == out[i] + 1)
            end = i;
        
        if (in[i] + 1 == out[i])
            start = i;
    }

    getEulerTrail(start, end, adj, trail);
    reverse(trail.begin(), trail.end());
    
    for (int i = 0; i < trail.size(); ++i)
        cout << trail[i] << ' ';

    return 0;
}

void getEulerTrail(int start, int end, vector<vector<couple> >& adj, vector<int>& trail) {
    getEulerCircuit(start, adj, trail);
}

void getEulerCircuit(int start, vector<vector<couple> >& adj, vector<int>& circuit) {
    for (vector<couple>::iterator it = adj[start].begin(), end = adj[start].end(); it != end; ++it) {
        if (it -> second) {
            it -> second = false;
            getEulerCircuit(it -> first, adj, circuit);
        }
    }

    circuit.push_back(start);
}