#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

#define MaxN 101
const int INF = numeric_limits<int>::max();

int N, M;
int Map[MaxN][MaxN];
int TTS[MaxN];
bool Grouped[MaxN];
vector<int> GroupRep;

int main() {
    ios_base::sync_with_stdio(false);

    memset(Map, -1, sizeof(Map));
    memset(Grouped, 0, sizeof(Grouped));
    memset(TTS, -1, sizeof(TTS));

    cin >> N >> M;
    int u, v;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        Map[u][v] = 1;
        Map[v][u] = 1;
    }

    for (int k = 1; k <= N; ++k) {
        for (int u = 1; u <= N; ++u) {
            if (Map[u][k] == -1) continue;

            for (int v = 1; v <= N; ++v) {
                if (Map[k][v] == -1 || u == v) continue;

                if (Map[u][v] == -1)
                    Map[u][v] = Map[u][k] + Map[k][v];
                else
                    Map[u][v] = min(Map[u][v], Map[u][k] + Map[k][v]);
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == j || Map[i][j] == -1)
                continue;

            TTS[i] = max(TTS[i], Map[i][j]);
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (Grouped[i])
            continue;

        int minTTS = TTS[i];
        int minTTSNode = i;

        for (int j = 1; j <= N; ++j) {
            if (i != j && Map[i][j] != -1) {
                Grouped[j] = true;
                if (TTS[j] < minTTS) {
                    minTTS = TTS[j];
                    minTTSNode = j;
                }
            }
        }

        GroupRep.push_back(minTTSNode);
    }

    cout << GroupRep.size() << '\n';
    sort(GroupRep.begin(), GroupRep.end());
    for (int i = 0; i < GroupRep.size(); ++i)
        cout << GroupRep[i] << '\n';

    return 0;
}
