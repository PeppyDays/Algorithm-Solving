// http://bowbowbow.tistory.com/4

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N;

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

    void insert(int idx, int value) {
        idx += size;
        tree[idx] = value;
    }

    void init() {
        for (int i = size - 1; i >= 1; --i)
            tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    void propagate(int nIdx, int nLeft, int nRight) {
        if (lazy[nIdx]) {
            if (nLeft != nRight) {
                lazy[2 * nIdx] = lazy[nIdx];
                lazy[2 * nIdx + 1] = lazy[nIdx];
            }

            tree[nIdx] += (nRight - nLeft + 1) * lazy[nIdx];
            lazy[nIdx] = 0;
        }
    }

    int query(int left, int right, int nIdx, int nLeft, int nRight) {
        // 일부 혹은 전체가 포함되므로 lazy propagation 해야함
        propagate(nIdx, nLeft, nRight);

        // nLeft <= x <= nRight 안에 포함되어 있지 않으면 lazy propagation 필요가 없지 않나?
        if (left > nRight || right < nLeft)
            return 0;

        if (left <= nLeft && right >= nRight)
            return tree[nIdx];

        int nMid = nLeft + (nRight - nLeft) / 2;
        int leftRet = query(left, right, 2 * nIdx, nLeft, nMid);
        int rightRet = query(left, right, 2 * nIdx + 1, nMid + 1, nRight);

        return leftRet + rightRet;
    }

    int query(int left, int right) {
        return query(left, right, 1, 0, size - 1);
    }

    void update(int idx, int value) {
        idx += size;
        tree[idx] = value;
        idx /= 2;

        while (idx >= 1) {
            tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
            idx /= 2;
        }
    }

    void update_range(int left, int right, int nIdx, int nLeft, int nRight, int delta) {
        propagate(nIdx, nLeft, nRight);

        // 범위 포함 안되면 lazy propagation 필요없을 것 같아
        if (left > nRight || right < nLeft)
            return;

        if (left <= nLeft && right >= nRight) {
            lazy[nIdx] = delta;
            propagate(nIdx, nLeft, nRight);
            return;
        }

        int nMid = nLeft + (nRight - nLeft) / 2;
        update_range(left, right, 2 * nIdx, nLeft, nMid, delta);
        update_range(left, right, 2 * nIdx + 1, nMid + 1, nRight, delta);
        tree[nIdx] = tree[2 * nIdx] + tree[2 * nIdx + 1];
    }

    void update_range(int left, int right, int delta) {
        update_range(left, right, 1, 0, size - 1, delta);
    }
};

class FenwickTree {
public:
    vector<int> tree1;
    vector<int> tree2;

    FenwickTree(int n) {
        tree1.resize(n + 1);
        tree2.resize(n + 1);
    }

    int query(vector<int>& tree, int idx) {
        int ret = 0;

        while (idx > 0) {
            ret += tree[idx];
            idx &= (idx - 1);
        }

        return ret;
    }

    int query(int idx) {
        return query(tree1, idx) * idx - query(tree2, idx);
    }

    int query_range(int sIdx, int eIdx) {
        sIdx++;
        eIdx++;
        return query(eIdx) - query(sIdx - 1);
    }

    void update(vector<int>& tree, int idx, int delta) {
        while (idx < tree.size()) {
            tree[idx] += delta;
            idx += (idx & -idx);
        }
    }

    void update_range(int sIdx, int eIdx, int delta) {
        sIdx++;
        eIdx++;
        update(tree1, sIdx, delta);
        update(tree1, eIdx + 1, -delta);
        update(tree2, sIdx, delta * (sIdx - 1));
        update(tree2, eIdx + 1, -delta * eIdx);
    }
};

int main() {
    freopen("resources/input.in", "r", stdin);
    ios_base::sync_with_stdio(false);

    cin >> N;
    SegmentTree st = SegmentTree(N);
    FenwickTree ft = FenwickTree(N);

    for (int i = 0; i < N; i++) {
        int buf;
        cin >> buf;
        st.insert(i, buf);
        ft.update_range(i, i, buf);
    }

    st.init();

    st.update_range(1, 3, 5);
    ft.update_range(1, 3, 5);

    cout << st.query(0, 4) << endl;
    cout << ft.query_range(0, 4) << endl;

    st.update_range(2, 9, -1);
    ft.update_range(2, 9, -1);

    cout << st.query(3, 9) << endl;
    cout << ft.query_range(3, 9) << endl;

    return 0;
}
