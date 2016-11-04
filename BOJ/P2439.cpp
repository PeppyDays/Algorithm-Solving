#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;

    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++)
            cout << ' ';

        for (int j = 0; j < N - i; j++)
            cout << '*';

        cout << '\n';
    }

    return 0;
}

