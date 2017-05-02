#include <cstdio>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

typedef pair<int, int> couple;

const int MaxN = (1 << 17);
const int INF = numeric_limits<int>::max();
const int NINF = -1;

int n, modifiedN, q, temp, s, e;
couple ret;
couple signHeight[2 * MaxN];

couple init(int left, int right, int nIdx);
couple query(int left, int right, int nIdx, int nLeft, int nRight);

int main() {
    freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/input.in", "r", stdin);

    int C;
    scanf("%d", &C);

    while (C--) {
        scanf("%d %d", &n, &q);
        modifiedN = pow(2, int(log2(n) + 1));

        for (int i = modifiedN; i < modifiedN + n; ++i) {
            scanf("%d", &temp);
            signHeight[i] = make_pair(temp, temp);
        }

        for (int i = modifiedN + n; i < 2 * modifiedN; ++i) {
            signHeight[i] = make_pair(INF, NINF);
        }

        init(0, modifiedN - 1, 1);

        for (int i = 0; i < q; ++i) {
            scanf("%d %d", &s, &e);
            ret = query(s, e, 1, 0, modifiedN - 1);
            printf("%d\n", ret.second - ret.first);
        }
    }

    return 0;
}

couple init(int left, int right, int nIdx) {
    if (left == right)
        return signHeight[nIdx];

    int mid = left + (right - left) / 2;
    couple leftRet = init(left, mid, 2 * nIdx);
    couple rightRet = init(mid + 1, right, 2 * nIdx + 1);

    return signHeight[nIdx] = make_pair(min(leftRet.first, rightRet.first), max(leftRet.second, rightRet.second));
}

couple query(int left, int right, int nIdx, int nLeft, int nRight) {
    if (left > nRight || right < nLeft)
        return make_pair(INF, NINF);

    if (left <= nLeft && right >= nRight)
        return signHeight[nIdx];

    int nMid = nLeft + (nRight - nLeft) / 2;
    couple leftRet = query(left, right, nIdx * 2, nLeft, nMid);
    couple rightRet = query(left, right, nIdx * 2 + 1, nMid + 1, nRight);

    return make_pair(min(leftRet.first, rightRet.first), max(leftRet.second, rightRet.second));
}
