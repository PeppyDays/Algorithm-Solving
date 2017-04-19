#include <cstdio>
#include <algorithm>
#include <limits>
using namespace std;

typedef pair<int, int> couple;

const int INT_MAX = numeric_limits<int>::max();
const int MaxN = 1 << 17;

int n, N, M;
couple Segment[2 * MaxN];

couple find(int left, int right, int nIdx, int nLeft, int nRight);

int main() {
    freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/input.in", "r", stdin);

    scanf("%d %d", &n, &M);
    N = 1;

    while (N < n)
        N *= 2;

    for (int i = 0; i < n; ++i) {
        int temp;
        scanf("%d", &temp);
        Segment[N + i] = make_pair(temp, temp);
    }

    for (int i = n; i < N; ++i) {
        Segment[N + i] = make_pair(INT_MAX, -1);
    }

    for (int i = N - 1; i >= 1; --i) {
        Segment[i] = make_pair(min(Segment[2 * i].first, Segment[2 * i + 1].first),
                               max(Segment[2 * i].second, Segment[2 * i + 1].second));
    }

    for (int q = 0; q < M; ++q) {
        int left, right;
        scanf("%d %d", &left, &right);

        couple ret = find(left - 1, right - 1, 1, 0, N - 1);
        printf("%d %d\n", ret.first, ret.second);
    }

    return 0;
}

couple find(int left, int right, int nIdx, int nLeft, int nRight) {
    if (left > nRight || right < nLeft)
        return make_pair(INT_MAX, -1);

    if (left <= nLeft && right >= nRight)
        return Segment[nIdx];

    int nMid = nLeft + (nRight - nLeft) / 2;
    couple retLeft = find(left, right, 2 * nIdx, nLeft, nMid);
    couple retRight = find(left, right, 2 * nIdx + 1, nMid + 1, nRight);

    return make_pair(min(retLeft.first, retRight.first), max(retLeft.second, retRight.second));
}
