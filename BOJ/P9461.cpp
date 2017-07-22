#include <iostream>
#include <cstring>
using namespace std;

const int MaxN = 101;

long long Cache[MaxN];

long long get(int n) {
    if (Cache[n] != -1)
        return Cache[n];

    long long& ret = Cache[n];
    ret = get(n - 1) + get(n - 5); 

    return ret;
}

int main() {
    freopen("resources/input.in", "r", stdin);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    memset(Cache, -1, sizeof(Cache));
    Cache[0] = 0;
    Cache[1] = 1;
    Cache[2] = 1;
    Cache[3] = 1;
    Cache[4] = 2;
    Cache[5] = 2;

    while (T--) {
        int N;
        cin >> N;

        cout << get(N) << '\n';
    }

    return 0;
}