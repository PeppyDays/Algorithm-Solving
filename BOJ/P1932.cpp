#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char in[1000000];
const char* o;

void getIn() {
    o = in;
    in[fread(in, 1, sizeof(in) - 4, stdin)] = '\n';
}

int next() {
    int ret = 0;
    while (*o < '0' || *o > '9') ++o;
    while (*o >= '0' && *o <= '9') ret = 10 * ret + *o++ - '0';
    return ret;
}

const int MaxN = 500;

int N;
int tri[MaxN][MaxN];
int cache[MaxN][MaxN];

int findPath(int x, int y);

int main() {
    freopen("resources/input.in", "r", stdin);
    getIn();

    N = next();
    for (int i = 0; i < N; ++i)
        for (int j = 0; j <= i; ++j)
            tri[i][j] = next();

    memset(cache, -1, sizeof(cache));
    printf("%d\n", findPath(0, 0));

    return 0;
}

int findPath(int x, int y) {
    if (x == N - 1)
        return tri[x][y];

    if (cache[x][y] != -1)
        return cache[x][y];

    int& ret = cache[x][y];

    int downPath = findPath(x + 1, y);
    int diagonalPath = findPath(x + 1, y + 1);

    ret = tri[x][y] + max(downPath, diagonalPath);
    return ret;
}
