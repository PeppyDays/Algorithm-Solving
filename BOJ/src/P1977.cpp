#include <iostream>
#include <math.h>
using namespace std;

long squareSum(int n);

int main() {
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> M >> N;

    int m, n;
    m = ceil(sqrt(M));
    n = floor(sqrt(N));

    if (m > n) {
        cout << -1 << '\n';
    }
    else {
        cout << squareSum(n) - squareSum(m - 1) << '\n';
        cout << m * m << '\n';
    }

    return 0;
}

long squareSum(int n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}
