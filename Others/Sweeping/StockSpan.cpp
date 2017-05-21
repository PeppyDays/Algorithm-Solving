// http://www.geeksforgeeks.org/the-stock-span-problem/

#include <cstdio>
#include <vector>
using namespace std;

class stack {
public:
    vector<int> data;
    int idx;

    stack(int n) { data.resize(n); idx = -1; }

    void push(int n) { data[++idx] = n; }
    int top() { return data[idx]; }
    void pop() { idx--; }
    bool empty() { return idx == -1; }
    void clear() { idx = -1;}
};

int main() {
    freopen("resources/input.in", "r", stdin);

    int N;
    scanf("%d", &N);
    vector<int> h(N);
    vector<int> ret(N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &h[i]);

    stack s(N);
    ret[0] = 1;
    s.push(0);

    for (int i = 1; i < N; ++i) {
        while (!s.empty() && h[s.top()] <= h[i])
            s.pop();

        ret[i] = s.empty() ? i + 1 : i - s.top();
        s.push(i);
    }

    printf("Original Data:\n");
    for (int i = 0; i < N; ++i)
        printf("%d ", h[i]);
    printf("\n");

    printf("Stock Span Data:\n");
    for (int i = 0; i < N; ++i)
        printf("%d ", ret[i]);
    printf("\n");



    return 0;
}
