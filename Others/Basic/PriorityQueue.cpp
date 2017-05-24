#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 10;

// min heap
template <typename T>
class priority_queue {
public:
    T data[MaxN + 1];
    int idx;

    priority_queue() {
        idx = 0;
    }

    void push(T n) {
        data[++idx] = n;
        int cIdx = idx, pIdx = cIdx / 2;

        while (pIdx > 0 && data[pIdx] > data[cIdx]) {
            swap(pIdx, cIdx);
            cIdx = pIdx;
            pIdx = cIdx / 2;
        }
    }

    void pop() {
        data[1] = data[idx--];
        int pIdx = 1, cIdx = 2;

        while (cIdx <= idx && (data[pIdx] > data[cIdx] || data[pIdx] > data[min(cIdx + 1, idx)])) {
            cIdx = data[cIdx] < data[min(cIdx + 1, idx)] ? cIdx : min(cIdx + 1, idx);
            swap(pIdx, cIdx);
            pIdx = cIdx;
            cIdx = 2 * pIdx;
        }
    }

    T top() {
        return data[1];
    }

    bool empty() {
        return idx <= 0;
    }

    int size() {
        return idx;
    }

    void swap(int pIdx, int cIdx) {
        T temp = data[pIdx];
        data[pIdx] = data[cIdx];
        data[cIdx] = temp;
    }

    int min(int u, int v) {
        return u > v ? v : u;
    }
};

int main() {
    priority_queue<pair<int, int> > pq;

    pq.push(make_pair(1, 3));
    pq.push(make_pair(4, 1));
    pq.push(make_pair(2, 3));
    pq.push(make_pair(-1, 0));
    pq.push(make_pair(9, 9));

    printf("%d\n", pq.size());

    while (!pq.empty()) {
        printf("%d %d\n", pq.top().first, pq.top().second);
        pq.pop();
    }


    return 0;
}