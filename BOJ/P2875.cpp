#include <iostream>
using namespace std;

int main() {
    freopen("resources/input.in", "r", stdin);
    ios_base::sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;

    while (K-- > 0) {
        if (N / 2 >= M)
            N--;
        else
            M--;
    }

    cout << (N / 2 > M ? M : N / 2) << '\n';

    return 0;
}