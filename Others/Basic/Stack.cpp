#include <cstdio>
using namespace std;

const int MaxN = 1000;

template <typename T>
class stack {
public:
    T data[MaxN];
    int idx;

    stack() {
        idx = -1;
    }

    void push(T n) {
        data[++idx] = n;
    };

    void pop() {
        idx--;
    }

    T top() {
        return data[idx];
    }

    bool empty() {
        return idx == -1;
    }

    int size() {
        return idx + 1;
    }
};


