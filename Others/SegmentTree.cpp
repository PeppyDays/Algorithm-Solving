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
        // k 에 n 보다 크거나 같은 2의 제곱수 중 가장 작은수를 찾아서 저장한다.
        int k = 1 << int(ceil(log2(n)));

        // SegmentTree 생성을 위해 2배로 배열을 할당한다.
        tree.resize(2 * k);
    }

    // insert(): 데이터를 입력받을 때, tree 에 최초로 넣기 위한 함수, 후에 반드시 init() 을 호출해서 부모 노드의 정보를 채워주어야 한다.
    void insert(int idx, int value) {
        // 데이터는 N = 8 일 때, index 가 8 ~ 15 에 데이터가 채워져야 하므로..
        idx += tree.size() / 2;
        tree[idx] = value;
    }

    // init(): 상위 부모노드의 값을 추출해서 저장한다.
    void init() {
        // 노드 1 ~ tree.size() / 2 - 1 : 부모노드
        // 노드 tree.size() / 2 ~ tree.size() -1 : Raw 데이터 들어있는 최하위노드
        // 노드 i 의 자식은 2 * i, 2 * i + 1
        for (int i = tree.size() / 2 - 1; i >= 1; --i)
            tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    // query(): 부분합을 구한다.
    //   ㄴ left, right: 조건으로 들어온 구간의 왼쪽, 오른쪽 인덱스 값, 0 부터 시작할 수 있다.
    //   ㄴ nIdx, nLeft, nRight: 현재 재귀함수의 노드 번호와 그 노드가 커버하는 인덱스 번호 (nIdx 가 1 이면 ST 의 루트이고, 커버하는 인덱스는 0 ~ N - 1 까지 커버한다.)
    int query(int left, int right, int nIdx, int nLeft, int nRight) {
        // 이 노드의 커버리지가 조건의 구간과 겹치는 곳이 없다면, 0 출력
        if (left > nRight || right < nLeft)
            return 0;

        // 이 노드의 커버리지가 조건의 구간에 완전히 포함된다면, 노드의 값(해당 커버리지의 모든 합) 출력
        if (left <= nLeft && right >= nRight)
            return tree[nIdx];

        // nMid: 노드 커버리지의 중간에 위치하는 인덱스값
        int nMid = nLeft + (nRight - nLeft) / 2;

        int leftRet = query(left, right, 2 * nIdx, nLeft, nMid);
        int rightRet = query(left, right, 2 * nIdx + 1, nMid + 1, nRight);

        return leftRet + rightRet;
    }

    // query(): 부분합을 구한다. 메인함수에서 호출할 떄 사용한다.
    int query(int left, int right) {
        // 모든 검색은 루트에서부터 시작하므로 아래와 같이 실제 query() 함수 호출한다.
        return query(left, right, 1, 0, tree.size() / 2 - 1);
    }

    // update(): idx (0 부터 시작) 의 값을 value 로 치환한다.
    void update(int idx, int value) {
        // idx 노드의 값은 실제 tree 에는 N + idx 에 위치하므로
        idx += tree.size() / 2;
        tree[idx] = value;
        idx /= 2;

        // 1차 부모노드에서 시작해서, 자식들을 이용해 자신의 부분합을 다시 구한다.
        while (idx >= 1) {
            tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
            idx /= 2;
        }

        // 물론 부분합이므로 불필요하게 위와 같이 합을 전부 다시 구할 필요는 없지만,
        // 연산이 합이 아니라 다른 것이라면 위와 같이 해당 경로의 모든 값을 다시 계산해주어야 한다.
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
