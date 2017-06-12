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

const int MaxN = 1001;

int N, P[MaxN], cache[MaxN];

int findMaxProfit(int n);

int main() {
    freopen("resources/input.in", "r", stdin);
    memset(cache, -1, sizeof(cache));
    getIn();
    N = nextInt();
    for (int i = 1; i <= N; ++i)
        P[i] = nextInt();

    printf("%d\n", findMaxProfit(N));

    return 0;
}

int findMaxProfit(int n) {
    if (n == 0)
        return 0;

    if (n == 1)
        return P[1];

    if (cache[n] != -1)
        return cache[n];

    int& ret = cache[n];

    for (int i = 1; i <= n; ++i)
        ret = max(ret, P[i] + findMaxProfit(n - i));

    return ret;
}