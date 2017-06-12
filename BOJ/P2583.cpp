#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char in[2000000];
const char* o;

void getIn() {
    o = in;
    in[fread(in, 1, sizeof(in) - 4, stdin)] = '\n';
}

int nextInt() {
    int ret = 0;
    while (*o < '0' || *o > '9') ++o;
    while (*o >= '0' && *o <= '9') ret = 10 * ret + *o++ - '0';
    return ret;
}

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int MaxN = 100, MaxM = 100;

int N, M, K;
bool Paper[MaxM][MaxN];

int dfs(int x, int y);

int main() {
    freopen("resources/input.in", "r", stdin);
    memset(Paper, 0, sizeof(Paper));
    getIn();
    N = nextInt(); M = nextInt(); K = nextInt();

    int x, y, u, v;
    for (int i = 0; i < K; ++i) {
        x = nextInt(); y = nextInt();
        u = nextInt(); v = nextInt();

        for (int i = x; i < u; ++i)
            for (int j = y; j < v; ++j)
                Paper[i][j] = true;
    }

    int retIdx = 0;
    int retSize[MaxM * MaxN];
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            if (!Paper[i][j])
                retSize[retIdx++] = dfs(i, j);

    sort(retSize, retSize + retIdx);

    printf("%d\n", retIdx);
    for (int i = 0; i < retIdx; ++i)
        printf("%d ", retSize[i]);

    return 0;
}

int dfs(int x, int y) {
    if (x < 0 || x >= M || y < 0 || y >= N)
        return 0;

    Paper[x][y] = true;

    int ret = 1, nx, ny;
    for (int i = 0; i < 4; ++i) {
        nx = x + dx[i]; ny = y + dy[i];

        if (!Paper[nx][ny])
            ret += dfs(nx, ny);
    }

    return ret;
}