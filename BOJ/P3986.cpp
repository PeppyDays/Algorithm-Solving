#include <cstdio>
#include <stack>
using namespace std;

const int MaxS = 100000;

int N, M;
char A[MaxS];

int main() {
    freopen("resources/input.in", "r", stdin);
    scanf("%d", &N);
    int ret = 0;

    for (int n = 0; n < N; ++n) {
        M = 0;
        scanf("%s", A);
        while (A[M] != '\0') ++M;

        stack<char> s;
        for (int i = 0; i < M; ++i) {
            if (!s.empty() && s.top() == A[i])
                s.pop();
            else
                s.push(A[i]);
        }

        if (s.empty())
            ret++;
    }

    printf("%d", ret);

    return 0;
}