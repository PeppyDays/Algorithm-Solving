#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

class edge {
public:
    int to;
    string word;
    bool isLeft;

    edge(int _to, string _word) {
        to = _to;
        word = _word;
        isLeft = true;
    }
};

int n, C;
vector<edge> adj[26];
int in[26], out[26];
vector<string> result;

pair<bool, int> isEuler();
void findEulerCircuit(int here);

int main() {
    ios_base::sync_with_stdio(false);
    freopen("/Users/Donald/Documents/Algorithm-Solving/resources/input.in", "r", stdin);

    cin >> C;
    while (C--) {
        cin >> n;

        for (int i = 0; i < 26; ++i) adj[i].clear();
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        result.clear();

        for (int i = 0; i < n; ++i) {
            string w;
            cin >> w;
            int u = w[0] - 'a';
            int v = w[w.size() - 1] - 'a';
            adj[u].push_back(edge(v, w));
            in[v]++;
            out[u]++;
        }

        pair<bool, int> check = isEuler();
        if (check.first) {
            findEulerCircuit(check.second);

            if (result.size() == n) {
                reverse(result.begin(), result.end());
                for (int i = 0; i < result.size(); ++i)
                    cout << result[i] << ' ';
            }
            else
                cout << "IMPOSSIBLE";
        }
        else {
            cout << "IMPOSSIBLE";
        }
        cout << '\n';
    }

    return 0;
}

pair<bool, int> isEuler() {
    int startCnt = 0, endCnt = 0, startIdx = -1;
    for (int i = 0; i < 26; ++i) {
        if (in[i] == out[i])
            continue;

        if (in[i] == out[i] + 1) {
            endCnt++;
            continue;
        }

        if (out[i] == in[i]  + 1) {
            startCnt++;
            startIdx = i;
            continue;
        }

        return make_pair(false, 0);
    }

    if ((startCnt == 1 && endCnt == 1) || (startCnt == 0 && endCnt == 0)) {
        if (startIdx == -1)
            for (int i = 0; i < 26; ++i)
                if (in[i] != 0)
                    startIdx = i;

        return make_pair(true, startIdx);
    }

    return make_pair(false, 0);
}

void findEulerCircuit(int here) {
    for (vector<edge>::iterator it = adj[here].begin(), end = adj[here].end(); it != end; ++it) {
        if (it -> isLeft) {
            it -> isLeft = false;
            findEulerCircuit(it -> to);
            result.push_back(it -> word);
        }
    }
}
