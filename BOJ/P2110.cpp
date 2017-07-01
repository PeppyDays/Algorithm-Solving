#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 200001;
int N, C, H[MaxN];

bool check(int mid, int k);

int main() {
    freopen("resources/input.in", "r", stdin);
    scanf("%d %d", &N, &C);
    for (int i = 0; i < N; ++i)
        scanf("%d", H + i);

    sort(H, H + N);

    int start = 1, end = H[N - 1] - H[0], Answer = 1, mid;
    while (start <= end) {
        mid = start + (end - start) / 2;

        if (check(mid, C)) {
            if (Answer < mid) Answer = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }

        printf("%d", Answer);
        return 0;
    }


    return 0;
}

bool check(int mid, int k) {
    int cnt = 1, start = H[0];

    for (int i = 1; i < N; ++i)
        if (H[i] - start >= mid) {
            cnt++; start = H[i];
        }

    return cnt >= k;
}