#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, K;

class SegmentTree {
public:
    vector<long long> tree;
    vector<long long> lazy;

    SegmentTree(int n) {
        n = 1 << (ceil(log2(n)) + 1);

        tree.resize(n);
        lazy.resize(n);
    }

    void insert(int idx, long long value) {
        idx += tree.size() / 2;
        tree[idx] = value;
    }

    void init() {
        for (int i = tree.size() / 2 - 1; i >= 1; --i)
            tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    long long query(int left, int right, int nIdx, int nLeft, int nRight) {
        if (lazy[nIdx]) {
            tree[nIdx] += (nRight - nLeft + 1) * lazy[nIdx];
            if (nLeft != nRight) {
                lazy[2 * nIdx] = lazy[nIdx];
                lazy[2 * nIdx + 1] = lazy[nIdx];
            }
            lazy[nIdx] = 0;
        }

        if (left > nRight || right < nLeft)
            return 0;

        if (left <= nLeft && right >= nRight)
            return tree[nIdx];

        int nMid = nLeft + (nRight - nLeft) / 2;
        long long leftRet = query(left, right, 2 * nIdx, nLeft, nMid);
        long long rightRet = query(left, right, 2 * nIdx + 1, nMid + 1, nRight);

        return leftRet + rightRet;
    }

    long long query(int left, int right) {
        return query(left, right, 1, 0, tree.size() / 2 - 1);
    }

    void update(int idx, long long value) {
        idx += tree.size() / 2;
        tree[idx] = value;
        idx /= 2;

        while (idx >= 1) {
            tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
            idx /= 2;
        }
    }

    void update_range(int left, int right, int nIdx, int nLeft, int nRight, long long delta) {
        if (lazy[nIdx]) {
            tree[nIdx] += (nRight - nLeft + 1) * lazy[nIdx];
            if (nLeft != nRight) {
                lazy[2 * nIdx] += lazy[nIdx];
                lazy[2 * nIdx + 1] += lazy[nIdx];
            }
            lazy[nIdx] = 0;
        }

        if (left > nRight || right < nLeft)
            return;

        if (left <= nLeft && right >= nRight) {
            tree[nIdx] += (nRight - nLeft + 1) * delta;
            if (nLeft != nRight) {
                lazy[2 * nIdx] += delta;
                lazy[2 * nIdx + 1] += delta;
            }
            return;
        }

        int nMid = nLeft + (nRight - nLeft) / 2;
        update_range(left, right, 2 * nIdx, nLeft, nMid, delta);
        update_range(left, right, 2 * nIdx + 1, nMid + 1, nRight, delta);
        tree[nIdx] = tree[2 * nIdx] + tree[2 * nIdx + 1];
    }

    void update_range(int left, int right, long long delta) {
        update_range(left, right, 1, 0, tree.size() / 2 - 1, delta);
    }
};

int nextInt() {
    int buf = getchar(), ret = 0;

    while (buf < '0' || buf > '9') buf = getchar();
    while (buf >= '0' && buf <= '9') {
        ret = ret * 10 + (buf - '0');
        buf = getchar();
    }
    return ret;
}

int nextLongLong() {
    int buf = getchar(), sign = 1;
    long long ret = 0;

    while ((buf < '0' || buf > '9') && buf != '-') {
        buf = getchar();
    }

    if (buf == '-') {
        sign = -1;
        buf = getchar();
    }

    while (buf >= '0' && buf <= '9') {
        ret = ret * 10 + (buf - '0');
        buf = getchar();
    }

    return sign * ret;
}

int main() {
    freopen("resources/input.in", "r", stdin);

    N = nextInt();
    M = nextInt();
    K = nextInt();
    SegmentTree st = SegmentTree(N);

    long long inputTemp;
    for (int i = 0; i < N; ++i) {
        inputTemp = nextLongLong();
        st.insert(i, inputTemp);
    }

    st.init();

    int a, b, c;
    long long d;

    for (int i = 0; i < M + K; ++i) {
        a = nextInt();
        b = nextInt();
        c = nextInt();

        if (a - 1)
            printf("%lld\n", st.query(b - 1, c - 1));
        else {
            d = nextLongLong();
            st.update_range(b - 1, c - 1, d);
        }
    }

    return 0;
}