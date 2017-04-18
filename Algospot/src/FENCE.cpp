#include <iostream>
#include <algorithm>
using namespace std;

const int MaxN = 20000;

int N;
int fence[MaxN];

int solve(int left, int right);

int main() {
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 0; i < N; ++i)
            cin >> fence[i];

        cout << solve(0, N - 1) << '\n';
    }

    return 0;
}

int solve(int left, int right) {
    if (left == right)
        return fence[left];

    int mid = left + (right - left) / 2;

    int resLeft = solve(left, mid);
    int resRight = solve(mid + 1, right);

    int li = mid, ri = mid + 1, height = min(fence[li], fence[ri]);
    int resMid = 2 * height;

    while (li > left || ri < right) {
        if (ri < right && fence[li - 1] <= fence[ri + 1]) {
            height = min(height, fence[ri + 1]);
            ri++;
        }
        else {
            height = min(height, fence[li - 1]);
            li--;
        }

        resMid = max(resMid, (ri - li + 1) * height);
    }

    return max(max(resLeft, resRight), resMid);
}
