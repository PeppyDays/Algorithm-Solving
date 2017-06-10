#include <cstdio>
#include <cstring>
#include <limits>
#include <algorithm>
using namespace std;

char in[10000000];
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

const int INF = numeric_limits<int>::max();
const int MaxN = 100, MaxK = 10001;

int N, K;
int coin[MaxN];
int cache[MaxK];

int findMinCoins(int value);

int main() {
    freopen("resources/input.in", "r", stdin);
    getIn();

    N = next();
    K = next();
    for (int i = 0; i < N; ++i)
        coin[i] = next();

    memset(cache, -1, sizeof(cache));

    int ret = findMinCoins(K);
    printf("%d\n", ret == -2 ? -1 : ret);

    return 0;
}

int findMinCoins(int value) {
    if (value < 0)
        return -2;

    if (value == 0)
        return 0;

    if (cache[value] != -1)
        return cache[value];

    int& ret = cache[value];
    ret = INF;

    for (int i = 0; i < N; ++i) {
        int subRet = findMinCoins(value - coin[i]);

        if (subRet == -2)
            continue;

        ret = min(ret, subRet + 1);
    }

    ret = (ret == INF ? -2 : ret);
    return ret;
}

