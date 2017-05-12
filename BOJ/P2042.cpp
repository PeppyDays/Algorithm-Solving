#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;

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
    int buf = getchar();
    long long ret = 0;
    while (buf < '0' || buf > '9') buf = getchar();
    while (buf >= '0' && buf <= '9') {
        ret = ret * 10 + (buf - '0');
        buf = getchar();
    }
    return ret;
}

class SegmentTree {
public:
    vector<long long> tree;

    SegmentTree(int n) {
        int k = 1;
        while (k < n)
            k = k << 1;

        tree.resize(2 * k);
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

    void update(int idx, long long delta) {
        idx += tree.size() / 2;

        while (idx >= 1) {
            tree[idx] += delta;
            idx /= 2;
        }
    }
};

int main() {
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
    for (int i = 0; i < M + K; ++i) {
        a = nextInt();
        b = nextInt();
        c = nextInt();

        if (a - 1)
            printf("%lld\n", st.query(b - 1, c - 1));
        else
            st.update(b - 1, (long long)c - st.query(b - 1, b - 1));
    }

    return 0;
}
