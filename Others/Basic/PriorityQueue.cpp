#include <cstdio>
using namespace std;

const int MaxN = 1000;

// min heap
template <typename T>
class priority_queue {
public:
    T data[MaxN + 1];
    int idx;

    priority_queue() {
        idx = -1;
    }

    void push(T n) {
        data[++idx] = n;
        int cIdx = idx - 1, pIdx = cIdx / 2;

        while (pIdx > 0 && data[pIdx] > data[cIdx]) {
            swap(pIdx, cIdx);
            cIdx = pIdx;
            pIdx = cIdx / 2;
        }
    }

    void pop() {
        data[1] = data[idx--];
        int pIdx = 1, cIdx = 2;

        while (cIdx <= idx && (data[pIdx] > data[cIdx] || data[pIdx] > data[cIdx + 1])) {

        }
    }

    void swap(int pIdx, int cIdx) {
        T temp = data[pIdx];
        data[pIdx] = data[cIdx];
        data[cIdx] = T;
    }
};

int main() {

    return 0;
}