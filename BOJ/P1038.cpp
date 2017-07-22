#include <iostream>
#include <cstring>
using namespace std;

int Cache[1000][10];

int main() {
    freopen("resources/input.in", "r", stdin);
    ios_base::sync_with_stdio(false);

    memset(Cache, 0, sizeof(Cache));

    int N;
    cin >> N;

    int sum = 0;
    int ret;
    bool flag = false;

    for (int i = 1; i < 10; ++i) {
        Cache[1][i] = 1;
        sum += 1;

        if (sum == N) {
            ret = i;
            flag = true;
        }
    }

    if (flag) {
        cout << ret;
        return;
    }

    // f(3, 2) = f(2, 1)
    // f(3, 3) = f(2, 1) + f(2, 2)

    for (int i = 2; i < 10; ++i) {
        for (int j = 1; j < 10; ++j) {
            for (int k = 0; k < j; ++k) {
                Cache[i][j] += Cache[i - 1][k];
            }
        }
    }



    for (int i = 1; i < 7; ++i)


    return 0;
}