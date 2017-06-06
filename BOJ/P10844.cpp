#include <cstdio>
#include <cstring>
using namespace std;

const int R = 1000000000;
const int MaxN = 101;

int N;
int cache[MaxN][10];

int findStep(int l, int s);

int main() {
    freopen("resources/input.in", "r", stdin);
    scanf("%d", &N);
    memset(cache, -1, sizeof(cache));

    int ret = 0;
    for (int i = 1; i <= 9; ++i)
        ret = (ret + findStep(N, i)) % R;

    printf("%d\n", ret);

    return 0;
}

int findStep(int l, int s) {
    if (s < 0 || s > 9)
        return 0;

    if (l == 1)
        return 1;

    if (cache[l][s] != -1)
        return cache[l][s];

    int& ret = cache[l][s];

    int upRet = findStep(l - 1, s + 1);
    int downRet = findStep(l - 1, s - 1);

    ret = (upRet + downRet) % R;
    return ret;
}
