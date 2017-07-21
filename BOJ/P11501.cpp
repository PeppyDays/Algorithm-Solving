#include <cstdio>
using namespace std;

const int MaxN = 1000000;

template <typename T>
class stack {
public:
    T data[MaxN];
    int idx;
    stack() { idx = -1; }
    void push(T n) { data[++idx] = n; };
    void pop() { idx--; }
    T top() { return data[idx]; }
    bool empty() { return idx == -1; }
    int size() { return idx + 1; }
};

int stock[MaxN];

int main() {
    freopen("resources/input.in", "r", stdin);

    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        for (int i = 0; i < N; ++i)
            scanf("%d", stock + N - 1 - i);





    }

    return 0;
}