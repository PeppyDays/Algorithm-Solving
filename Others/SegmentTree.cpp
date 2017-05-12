// http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220791986409

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

class SegmentTree {
public:
    vector<int> tree;

    SegmentTree(int n) {
        int k = 1;
        while (k < n)
            k = k << 1;
        
        tree.resize(2 * k);
    }

    void insert(int idx, int value) {
        idx += tree.size() / 2;
        tree[idx] = value;
    }

    void init() {
        for (int i = tree.size() / 2 - 1; i >= 1; --i)
            tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    int query(int left, int right, int nIdx, int nLeft, int nRight) {
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
        return query(left, right, 1, 0, tree.size() / 2 - 1);
    }

    void update(int idx, int value) {
        idx += tree.size() / 2;
        tree[idx] = value;
        idx /= 2;

        while (idx >= 1) {
            tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
            idx /= 2;
        }
    }
};

class FenwickTree {
public:
    vector<int> tree;

    FenwickTree(int n) {
        tree.resize(n + 1);
    }

    int query(int idx) {
        idx++;
        int ret = 0;

        while (idx > 0) {
            ret += tree[idx];
            idx &= (idx - 1);
        }

        return ret;
    }

    int query(int sIdx, int eIdx) {
        return query(eIdx) - query(sIdx - 1);
    }

    void update(int idx, int delta) {
        idx++;
        while (idx < tree.size()) {
            tree[idx] += delta;
            idx += (idx & -idx);
        }
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
        ft.update(i, buf);
    }

    st.init();

    st.update(2, 1);
    ft.update(2, 4);

    cout << st.query(2, 2) << '\n';
    cout << ft.query(2, 2) << '\n';

    cout << st.query(0, 3) << '\n';
    cout << ft.query(0, 3) << '\n';

    cout << st.query(0, N) << '\n';
    cout << ft.query(0, N) << '\n';

    return 0;
}
