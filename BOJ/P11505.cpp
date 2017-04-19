#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 1 << 20;
const int R = 1000000007;

int n, N, M, K;
long long Line[2 * MaxN];

int powUpperBound(int n);
long long multiply(int left, int right, int nIdx, int nLeft, int nRight);
void update(int idx, long long v);

int main() {
    freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/input.in", "r", stdin);

    scanf("%d %d %d", &n, &M, &K);
    N = powUpperBound(n);

    for (int i = 0; i < n; ++i) {
        scanf("%lld", Line + N + i);
        Line[N + i] %= R;
    }

    for (int i = n; i < N; ++i)
        Line[N + i] = 1;

    for (int i = N - 1; i >= 1; --i)
        Line[i] = (Line[2 * i] * Line[2 * i + 1]) % R;

    int a, b, c;
    for (int i = 0; i < M + K; ++i) {
        scanf("%d %d %d", &a, &b, &c);

        if (a - 1)
            printf("%lld\n", multiply(b - 1, c - 1, 1, 0, N - 1));
        else
            update(b - 1, c);
    }

    return 0;
}

int powUpperBound(int n) {
    int i = 1;
    while (i < n)
        i *= 2;

    return i;
}

long long multiply(int left, int right, int nIdx, int nLeft, int nRight) {
    if (left > nRight || right < nLeft)
        return 1;

    if (left <= nLeft && right >= nRight)
        return Line[nIdx];

    int nMid = nLeft + (nRight - nLeft) / 2;

    long long retLeft = multiply(left, right, 2 * nIdx, nLeft, nMid);
    long long retRight = multiply(left, right, 2 * nIdx + 1, nMid + 1, nRight);

    return (retLeft * retRight) % R;
}

void update(int idx, long long v) {
    idx += N;
    Line[idx] = v;
    idx /= 2;

    while (idx >= 1) {
        Line[idx] = (Line[2 * idx] * Line[2 * idx + 1]) % R;
        idx /= 2;
    }

    return;
}
