// http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220791986409

#include <iostream>
#include <algorithm>
using namespace std;

const int MaxN = 10;

int N;
int SegmentSum[2 * MaxN];

int sum(int left, int right, int nodeIdx, int nodeLeft, int nodeRight);
void update(int i, int val);

int main() {
    freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/input.in", "r", stdin);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> SegmentSum[N + i];

    for (int i = N - 1; i >= 1; i--)
        SegmentSum[i] = SegmentSum[2 * i] + SegmentSum[2 * i + 1];

    // cout << sum(4, 7, 1, 0, N - 1) << endl;

    update(2, 4);

    cout << SegmentSum[1] << endl;

    return 0;
}

int sum(int left, int right, int nodeIdx, int nodeLeft, int nodeRight) {
    if (right < nodeLeft || left > nodeRight)
        return 0;

    if (left == nodeLeft && right == nodeRight)
        return SegmentSum[nodeIdx];

    int nodeMid = nodeLeft + (nodeRight - nodeLeft) / 2;

    int retLeft = sum(left, min(right, nodeMid), 2 * nodeIdx, left, nodeMid);
    int retRight = sum(max(left, nodeMid + 1), right, 2 * nodeIdx + 1, nodeMid + 1, nodeRight);
    int ret = retLeft + retRight;

    return ret;
}

void update(int idx, int val) {
    idx += N;

    while (idx >= 1) {
        SegmentSum[idx] += val;
        idx /= 2;
    }

    return;
}
