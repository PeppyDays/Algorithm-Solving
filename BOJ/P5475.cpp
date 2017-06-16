#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 100000;

int N, food[MaxN], cache[1 << 4][1 << 4][MaxN], cacheScore[1 << 2][1 << 2][1 << 2];
int getCoal(int u, int v, int d);
int getScore(int s, int a);

int main() {
    freopen("resources/input.in", "r", stdin);
    memset(cache, -1, sizeof(cache));
    memset(cacheScore, -1, sizeof(cacheScore));

    char buf[MaxN];

    scanf("%d", &N);
    scanf("%s", buf);

    // M: 01  B: 10  F: 11
    for (int i = 0; i < N; ++i)
        food[i] = (buf[i] == 'M' ? 1 : (buf[i] == 'B' ? 2 : 3));

    printf("%d", getCoal(0, 0, 0));

    return 0;
}

int getScore(int a, int b, int c) {
    if (cacheScore[a][b][c] != -1)
        return cacheScore[a][b][c];

    int check[4] = {0};
    int& ret = cacheScore[a][b][c];
    ret = 0;

    ++check[a]; ++check[b]; ++check[c];

    for (int i = 1; i < 4; ++i)
        ret += (check[i] >= 1);

    return ret;
}

int getCoal(int u, int v, int d) {
    if (d == N)
        return 0;

    if (cache[u][v][d] != -1)
        return cache[u][v][d];

    int& ret = cache[u][v][d];

    // Give food to cave u
    int uStatus = ((u << 2) & ((1 << 4) - 1)) + food[d];
    int uScore = getScore(u & 3, u >> 2, food[d]);
    int uRet = uScore + getCoal(uStatus, v, d + 1);

    // Give food to cave v
    int vStatus = ((v << 2) & ((1 << 4) - 1)) + food[d];
    int vScore = getScore(v & 3, v >> 2, food[d]);
    int vRet = vScore + getCoal(u, vStatus, d + 1);

    ret = uRet > vRet ? uRet : vRet;
    return ret;
}
