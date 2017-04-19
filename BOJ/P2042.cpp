#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 1 << 20;

int n, N, M, K;
long long Line[2 * MaxN];

int powUpperBound(int n);
long long sum(int left, int right, int nIdx, int nLeft, int nRight);
void update(int idx, long long dv);

int main() {
    freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/input.in", "r", stdin);
    // freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/output.out", "w", stdout);

    scanf("%d %d %d", &n, &M, &K);
    N = powUpperBound(n);

    for (int i = 0; i < n; ++i)
        scanf("%lld", Line + N + i);

    for (int i = n; i < N; ++i)
        Line[N + i] = 0;

    for (int i = N - 1; i >= 1; --i)
        Line[i] = Line[2 * i] + Line[2 * i + 1];

    int a, b, c;
    for (int i = 0; i < M + K; ++i) {
        scanf("%d %d %d", &a, &b, &c);

        if (a - 1)
            printf("%lld\n", sum(b - 1, c - 1, 1, 0, N - 1));
        else
            update(b - 1, (long long)c - Line[N + b - 1]);
    }

    return 0;
}

int powUpperBound(int n) {
    int i = 1;
    while (i < n)
        i *= 2;

    return i;
}

long long sum(int left, int right, int nIdx, int nLeft, int nRight) {
    if (left > nRight || right < nLeft)
        return 0;

    if (left <= nLeft && right >= nRight)
        return Line[nIdx];

    int nMid = nLeft + (nRight - nLeft) / 2;
    return sum(left, right, 2 * nIdx, nLeft, nMid) + sum(left, right, 2 * nIdx + 1, nMid + 1, nRight);
}


void update(int idx, long long dv) {
    idx += N;

    while (idx >= 1) {
        Line[idx] += dv;
        idx /= 2;
    }

    return;
}
