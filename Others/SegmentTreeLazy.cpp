// http://bowbowbow.tistory.com/4

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

class SegmentTree {
public:
    vector<int> tree;
    vector<int> lazy;

    SegmentTree(int n) {
        int k = 1;
        while (k < n)
            k = k << 1;

        tree.resize(2 * k);
        lazy.resize(2 * k);
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

    void update_range(int left, int right, int nIdx, int nLeft, int nRight, int delta) {
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
                lazy[2 * nIdx] += lazy[nIdx];
                lazy[2 * nIdx + 1] += lazy[nIdx];
            }
            return;
        }

        int nMid = nLeft + (nRight - nLeft) / 2;
        update_range(left, right, 2 * nIdx, nLeft, nMid, delta);
        update_range(left, right, 2 * nIdx + 1, nMid + 1, nRight, delta);
        tree[nIdx] = tree[2 * nIdx] + tree[2 * nIdx + 1];
    }

    void update_range(int left, int right, int delta) {
        update_range(left, right, 1, 0, tree.size() / 2 - 1, delta);
    }
};

class FenwickTree {
public:
    vector<int> tree;

    FenwickTree(int n) {
        // 전체 크기에 1만 더 필요하다. 1~N 까지 데이터를 저장한다.
        tree.resize(n + 1);
    }

    // query(): 메인함수에서 호출할 때 0~idx 까지의 합을 출력한다.
    int query(int idx) {
        // 외부에서의 인덱스번호 시작은 0, 펜윅트리에서는 1부터 시작하므로, 1을 더해줘서 인덱스를 맞춘다.
        idx++;
        int ret = 0;

        while (idx > 0) {
            // idx 의 커버리지 부분합을 더한다.
            ret += tree[idx];
            // idx 의 커버리지 앞부분의 인덱스로 이동한다.
            idx &= (idx - 1);
        }

        return ret;
    }

    // query(): 메인함수에서 호출할 때 sIdx~eIdx 까지의 합을 출력한다.
    int query(int sIdx, int eIdx) {
        return query(eIdx) - query(sIdx - 1);
    }

    // update(): idx (0부터 시작) 에 delta 만큼을 더해준다.
    void update(int idx, int delta) {
        // 외부에서의 인덱스번호 시작은 0, 펜윅트리에서는 1부터 시작하므로, 1을 더해줘서 인덱스를 맞춘다.
        idx++;

        // idx 에서 상위로 올라가는 경로 안의 모든 것들에 대해 delta 를 더해주어야 한다.
        while (idx < tree.size()) {
            tree[idx] += delta;
            // 이번 커버리지가 끝나고 다음 상위 커버리지로 이동한다.
            idx += (idx & -idx);
        }
    }
};

int main() {
    freopen("resources/input.in", "r", stdin);
    ios_base::sync_with_stdio(false);

    cin >> N;
    SegmentTree st = SegmentTree(N);
    // FenwickTree ft = FenwickTree(N);

    for (int i = 0; i < N; i++) {
        int buf;
        cin >> buf;
        st.insert(i, buf);
        // ft.update(i, buf);
    }

    st.init();



    cout << st.query(2, 2) << '\n';
    // cout << ft.query(2, 2) << '\n';

    cout << st.query(0, 3) << '\n';
    // cout << ft.query(0, 3) << '\n';

    cout << st.query(0, N) << '\n';
    // cout << ft.query(0, N) << '\n';

    st.update_range(1, 3, 5);

    return 0;
}
