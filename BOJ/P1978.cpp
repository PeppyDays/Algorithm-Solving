#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    bool primeNumber[101];
    memset(primeNumber, 0, sizeof(primeNumber));
    primeNumber[1] = true;

    for (int i = 2; i <= 100; ++i) {
        if (primeNumber[i])
            continue;

        int m = 2;
        while (i * m <= 100) {
            primeNumber[i * m] = true;
            ++m;
        }
    }

    int N, P;
    int Answer = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> P;
        if (!primeNumber[P]) {
            ++Answer;
        }
    }

    cout << Answer;

    return 0;
}
