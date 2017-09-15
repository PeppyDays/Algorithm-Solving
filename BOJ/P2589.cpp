#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

typedef pair<int, int> couple;
const int MaxN = 50;
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int N, M;
char Board[MaxN][MaxN];

int bfs(couple start);

int main() {
    freopen("resources/input.in", "r", stdin);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        string temp;
        cin >> temp;

        for (int j = 0; j < M; ++j)
            Board[i][j] = temp[j];
    }

    int ret = -1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (Board[i][j] == 'L')
                ret = max(ret, bfs(make_pair(i, j)));
        }
    }

    cout << ret << '\n';
    return 0;
}

int bfs(couple start) {
    int dist[MaxN][MaxN] = {0, }, max_dist = -1;
    queue<couple> q;

    q.push(start);
    dist[start.first][start.second] = 1;

    while (!q.empty()) {
        couple here = q.front();
        q.pop();

        max_dist = max(max_dist, dist[here.first][here.second]);

        for (int i = 0; i < 4; ++i) {
            couple there = make_pair(here.first + dr[i], here.second + dc[i]);

            if (there.first < 0 || there.first >= N || there.second < 0 || there.second >= M)
                continue;

            if (dist[there.first][there.second] > 0)
                continue;

            if (Board[there.first][there.second] == 'W')
                continue;

            dist[there.first][there.second] = dist[here.first][here.second] + 1;
            q.push(there);
        }
    }

    return max_dist - 1;
}