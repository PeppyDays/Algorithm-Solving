#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    bool primeNumber[1000001];
    memset(primeNumber, 0, sizeof(primeNumber));
    primeNumber[1] = true;

    for (int i = 2; i <= 1000000; ++i) {
        if (primeNumber[i])
            continue;

        int m = 2;
        while (i * m <= 1000000) {
            primeNumber[i * m] = true;
            ++m;
        }
    }

    int N, M;
    cin >> M >> N;

    for (int i = M; i <= N; ++i) {
        if (!primeNumber[i]) {
            cout << i << '\n';
        }
    }

    return 0;
}
