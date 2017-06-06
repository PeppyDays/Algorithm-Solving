#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

char in[10000000];
const char* o;

void getIn() {
    o = in;
    in[fread(in, 1, sizeof(in) - 4, stdin)] = '\n';
}

int nextInt() {
    int ret = 0;
    bool sign = true;

    while ((*o < '0' || *o > '9') && *o != '-') ++o;
    if (*o == '-') { sign = false; o++; };
    while (*o >= '0' && *o <= '9') ret = 10 * ret + *o++ - '0';

    return sign ? ret : -ret;
}

const int MaxN = 100000, MaxM = 100000;

int N, M;

class SegmentTree {
public:
    int size;
    vector<int> tree;
    vector<int> lazy;

    SegmentTree(int n) {
        size = 1 << int(ceil(log2(n)));
        tree.resize(2 * size);
        lazy.resize(2 * size);
    }

    void propagate(int nIdx, int nLeft, int nRight) {
        if (lazy[nIdx]) {
            if (nLeft != nRight) {
                lazy[2 * nIdx] += lazy[nIdx];
                lazy[2 * nIdx + 1] += lazy[nIdx];
            }

            tree[nIdx] += (nRight - nLeft + 1) * lazy[nIdx];
            lazy[nIdx] = 0;
        }
    }

    int query(int left, int right, int nIdx, int nLeft, int nRight) {
        propagate(nIdx, nLeft, nRight);

        if (left > nRight || right < nLeft)
            return 0;

        if (left <= nLeft && right >= nRight)
            return tree[nIdx];

        int nMid = nLeft + (nRight - nLeft) / 2;
        int retLeft = query(left, right, 2 * nIdx, nLeft, nMid);
        int retRight = query(left, right, 2 * nIdx + 1, nMid + 1, nRight);

        return retLeft + retRight;
    }

    void update(int left, int right, int nIdx, int nLeft, int nRight, int delta) {
        propagate(nIdx, nLeft, nRight);

        if (left > nRight || right < nLeft)
            return;

        if (left <= nLeft && right >= nRight) {
            lazy[nIdx] = delta;
            propagate(nIdx, nLeft, nRight);
            return;
        }

        int nMid = nLeft + (nRight - nLeft) / 2;
        update(left, right, 2 * nIdx, nLeft, nMid, delta);
        update(left, right, 2 * nIdx + 1, nMid + 1, nRight, delta);
        tree[nIdx] = tree[2 * nIdx] + tree[2 * nIdx + 1];
    }

    void toggle(int left, int right) {
        int switchSum = query(left, right, 1, 0, size - 1);

        if (switchSum == right - left + 1)
            update(left, right, 1, 0, size - 1, -1);
        else if (switchSum == 0)
            update(left, right, 1, 0, size - 1, 1);
        else {
            int mid = left + (right - left) / 2;
            toggle(left, mid);
            toggle(mid + 1, right);
        }
    }
};

int main() {
    freopen("resources/input.in", "r", stdin);
    // getIn();
    // N = nextInt();
    // M = nextInt();
    scanf("%d %d", &N, &M);

    SegmentTree st = SegmentTree(N);

    int q, s, e;
    while (M--) {
        // q = nextInt();
        // s = nextInt() - 1;
        // e = nextInt() - 1;
        scanf("%d %d %d", &q, &s, &e);
        s--; e--;

        if (q) {
            printf("%d\n", st.query(s, e, 1, 0, st.size - 1));
        }
        else {
            st.toggle(s, e);
        }
    }

    return 0;
}