#include <iostream>
#include <cstring>
using namespace std;

bool are_friends[10][10];
bool taken[10];
int N, M;

int countPairs(bool taken[]) {
    int first = -1;

    for (int i = 0; i < N; ++i) {
        if (!taken[i]) {
            first = i;
            break;
        }
    }

    if (first == -1)
        return 1;

    int ret = 0;

    for (int p = first + 1; p < N; ++p) {
        if (!taken[p] && are_friends[first][p]) {
            taken[p] = taken[first] = true;
            ret += countPairs(taken);
            taken[p] = taken[first] = false;
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        memset(are_friends, 0, sizeof(bool) * 100);
        memset(taken, 0, sizeof(bool) * 10);

        cin >> N >> M;

        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            are_friends[u][v] = are_friends[v][u] = true;
        }

        int Answer = countPairs(taken);

        cout << Answer << '\n';
    }

    return 0;
}
