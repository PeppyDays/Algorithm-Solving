#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    bool primeNumber[10001];
    memset(primeNumber, 0, sizeof(primeNumber));
    primeNumber[1] = true;

    for (int i = 2; i <= 10000; ++i) {
        if (primeNumber[i])
            continue;

        int m = 2;
        while (i * m <= 10000) {
            primeNumber[i * m] = true;
            ++m;
        }
    }

    int N, M;
    cin >> M >> N;

    int minPrime = 10002;
    int sumPrime = 0;

    for (int i = M; i <= N; ++i) {
        if (!primeNumber[i]) {
            sumPrime += i;
            minPrime = min(minPrime, i);
        }
    }

    if (sumPrime == 0)
        cout << -1;
    else
        cout << sumPrime << '\n' << minPrime;

    return 0;
}
