#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<short, short> couple;

const short dx[4] = { -1, 0, 1, 0 };
const short dy[4] = { 0, 1, 0, -1 };
const short MaxN = 100;

short N, A[MaxN][MaxN], H;

inline short max(short u, short v) {
    return u > v ? u : v;
}

short getShelter() {
    bool visited[MaxN][MaxN];
    memset(visited, 0, sizeof(visited));
    short ret = 0;

    for (short i = 0; i < N; ++i) {
        for (short j = 0; j < N; ++j) {
            if (!visited[i][j] && A[i][j]) {
                ++ret;
                visited[i][j] = true;
                queue<couple> q;
                q.push(make_pair(i, j));

                while (!q.empty()) {
                    couple here = q.front();
                    q.pop();

                    for (short k = 0; k < 4; ++k) {
                        couple there = make_pair(here.first + dx[k], here.second + dy[k]);

                        if (there.first < 0 || there.first >= N || there.second < 0 || there.second >= N || visited[there.first][there.second] || !A[there.first][there.second])
                            continue;

                        visited[there.first][there.second] = true;
                        q.push(there);
                    }
                }
            }
        }
    }

    return ret;
};

int main() {
    freopen("resources/input.in", "r", stdin);
    scanf("%hd", &N);
    for (short i = 0; i < N; ++i) {
        for (short j = 0; j < N; ++j) {
            scanf("%hd", &A[i][j]);
            H = max(H, A[i][j]);
        }
    }

    short ret = 1;
    for (short h = 1; h < H; ++h) {
        for (short i = 0; i < N; ++i)
            for (short j = 0; j < N; ++j)
                if (A[i][j] == h) A[i][j] = 0;

        short subRet = getShelter();
        ret = max(ret, subRet);
    }

    printf("%hd", ret);

    return 0;
}