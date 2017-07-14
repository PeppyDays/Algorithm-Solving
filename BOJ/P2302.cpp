#include <cstdio>
using namespace std;

const int MaxN = 41;

int N, M, F[MaxN];

int main() {
    freopen("resources/input.in", "r", stdin);
    scanf("%d", &N);
    scanf("%d", &M);

    F[0] = 1; F[1] = 1; F[2] = 2;
    for (int i = 3; i <= N; ++i)
        F[i] = F[i - 1] + F[i - 2];

    int s = 0, e, Answer = 1;
    for (int i = 0; i < M; ++i) {
        scanf("%d", &e);
        Answer *= F[e - s - 1];
        s = e;
    }

    Answer *= F[N - s];

    printf("%d\n", Answer);

    return 0;
}