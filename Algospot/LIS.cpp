#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 500;

int N, C, tIdx;
int A[MaxN], T[MaxN];

int main() {
    freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/input.in", "r", stdin);

    scanf("%d", &C);

    while (C--) {
        scanf("%d", &N);

        for (int i = 0; i < N; ++i)
            scanf("%d", A + i);

        tIdx = 1;
        T[0] = A[0];

        for (int i = 1; i < N; ++i) {
            int lowerIdx = int(lower_bound(T, T + tIdx, A[i]) - T);
            tIdx += ((lowerIdx == tIdx)? 1 : 0);
            T[lowerIdx] = A[i];
        }

        printf("%d\n", tIdx);
    }

    return 0;
}
