#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MaxN = 100000;

int n, h;
int floor[MaxN];
int ceil[MaxN];


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/input.in", "r", stdin);

    cin >> n >> h;
    n /= 2;
    int h1, h2;
    for (int i = 0; i < n; ++i) {
        cin >> h1 >> h2;
        floor[i] = h1;
        ceil[i] = h2;
    }

    sort(floor, floor + n);
    sort(ceil, ceil + n);

    int floor_cnt, ceil_cnt;
    int min_cnt = 2 * MaxN;
    int path_cnt = 0;

    for (int i = 0; i < h; ++i) {
        floor_cnt = n - int(upper_bound(floor, floor + n, i) - floor);
        ceil_cnt = n - int(lower_bound(ceil, ceil + n, h - i) - ceil);

        if (min_cnt > floor_cnt + ceil_cnt) {
            min_cnt = floor_cnt + ceil_cnt;
            path_cnt = 1;
        }
        else if (min_cnt == floor_cnt + ceil_cnt) {
            ++path_cnt;
        }
    }

    cout << min_cnt << ' ' << path_cnt << '\n';

    return 0;
}
