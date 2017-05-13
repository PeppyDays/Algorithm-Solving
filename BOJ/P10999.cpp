#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, K;

class SegmentTree {
public:
    int size;
    vector<long long> tree;
    vector<long long> lazy;

    SegmentTree(int n) {
        n = 1 << int(ceil(log2(n)) + 1);

        tree.resize(n);
        lazy.resize(n);
        size = n >> 1;
    }

    void insert(int idx, long long value) {
        idx += size;
        tree[idx] = value;
    }

    void init() {
        for (int i = size - 1; i >= 1; --i)
            tree[i] = tree[(i << 1)] + tree[(i << 1) + 1];
    }

    void propagate(int nIdx, int nLeft, int nRight) {
        if (lazy[nIdx]) {
            if (nLeft != nRight) {
                lazy[(nIdx << 1)] += lazy[nIdx];
                lazy[(nIdx << 1) + 1] += lazy[nIdx];
            }
            
            tree[nIdx] += (nRight - nLeft + 1) * lazy[nIdx];
            lazy[nIdx] = 0;
        }
    }

    long long query(int left, int right, int nIdx, int nLeft, int nRight) {
        propagate(nIdx, nLeft, nRight);

        if (left > nRight || right < nLeft)
            return 0;

        if (left <= nLeft && right >= nRight)
            return tree[nIdx];

        int nMid = nLeft + ((nRight - nLeft) >> 1);
        long long leftRet = query(left, right, (nIdx << 1), nLeft, nMid);
        long long rightRet = query(left, right, (nIdx << 1) + 1, nMid + 1, nRight);

        return leftRet + rightRet;
    }
    
    long long query(int left, int right) {
        return query(left, right, 1, 0, size - 1);
    }

    void update(int idx, long long value) {
        idx += size;
        tree[idx] = value;
        idx /= 2;

        while (idx >= 1) {
            tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
            idx /= 2;
        }
    }

    void update_range(int left, int right, int nIdx, int nLeft, int nRight, long long delta) {
        propagate(nIdx, nLeft, nRight);

        if (left > nRight || right < nLeft)
            return;

        if (left <= nLeft && right >= nRight) {
            lazy[nIdx] = delta;
            propagate(nIdx, nLeft, nRight);
            return;
        }

        int nMid = nLeft + ((nRight - nLeft) >> 1);
        update_range(left, right, (nIdx << 1), nLeft, nMid, delta);
        update_range(left, right, (nIdx << 1) + 1, nMid + 1, nRight, delta);
        tree[nIdx] = tree[(nIdx << 1)] + tree[(nIdx << 1) + 1];
    }
    
    void update_range(int left, int right, long long delta) {
        update_range(left, right, 1, 0, size - 1, delta);
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