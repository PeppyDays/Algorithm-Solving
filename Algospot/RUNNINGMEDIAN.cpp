#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int R = 20090711;

int N, a, b;

int next(int n);

int main() {
    freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/input.in", "r", stdin);
    ios_base::sync_with_stdio(false);

    int C;
    cin >> C;

    while (C--) {
        cin >> N >> a >> b;

        priority_queue<int, vector<int>, less<int> > maxHeap;
        priority_queue<int, vector<int>, greater<int> > minHeap;
        int ret = 0;
        int n = 1983;

        for (int cnt = 1; cnt <= N; ++cnt) {
            if (maxHeap.size() == minHeap.size())
                maxHeap.push(n);
            else {
                minHeap.push(n);
            }

            if (!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()) {
                int x = maxHeap.top(), y = minHeap.top();
                maxHeap.pop();
                minHeap.pop();
                maxHeap.push(y);
                minHeap.push(x);
            }

            ret = (ret + maxHeap.top()) % R;
            n = next(n);
        }

        cout << ret << '\n';
    }

    return 0;
}

int next(int n) {
    return int(((long long)n * a + b) % R);
}
