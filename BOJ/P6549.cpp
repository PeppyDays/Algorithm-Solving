#include <cstdio>
#include <algorithm>
#include <limits>
using namespace std;

typedef pair<int, int> couple;
const int INF = numeric_limits<int>::max();
const int MaxN = (1 << 17);

int n, N;
couple fence[2 * MaxN];

void init();
couple findMin(int left, int right, int nIdx, int nLeft, int nRight);
long solve(int left, int right);

int main() {
    while (true) {
        scanf("%d", &N);
        if (N == 0)
            break;

        for (int i = 0; i < N; ++i)
            scanf("%d", &fence[i].second);

        init();
        printf("%lld\n", solve(0, N - 1));
    }

    return 0;
}

void init() {
    n = 1;
    while (n < N)
        n *= 2;

    for (int i = 0; i < N; i++) {
        fence[n + i].first = i;
        fence[n + i].second = fence[i].second;
    }

    for (int i = N; i < n; i++)
        fence[n + i] = make_pair(i, INF);

    for (int i = n - 1; i >= 1; i--) {
        int minIdx = (fence[2 * i].second < fence[2 * i + 1].second) ? 2 * i : 2 * i + 1;
        fence[i].first = fence[minIdx].first;
        fence[i].second = fence[minIdx].second;
    }

    return;
}

couple findMin(int left, int right, int nIdx, int nLeft, int nRight) {
    if (left > nRight || right < nLeft)
        return make_pair(-1, INF);

    if (left <= nLeft && right >= nRight)
        return fence[nIdx];

    int nMid = nLeft + (nRight - nLeft) / 2;
    couple retLeft = findMin(left, right, 2 * nIdx, nLeft, nMid);
    couple retRight = findMin(left, right, 2 * nIdx + 1, nMid + 1, nRight);

    return (retLeft.second < retRight.second) ? retLeft : retRight;
}

long solve(int left, int right) {
    couple nMin = findMin(left, right, 1, 0, n - 1);
    long long ret = (long long)(right - left + 1) * nMin.second;
    long long retLeft = -1, retRight = -1;

    if (left < nMin.first)
        retLeft = solve(left, nMin.first - 1);

    if (right > nMin.first)
        retRight = solve(nMin.first + 1, right);

    ret = max(ret, max(retLeft, retRight));
    return ret;
}

