#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> couple;

bool Board[100][100];

int main() {
    freopen("/Users/Donald/Documents/SW/SW/input.in", "r", stdin);
    ios_base::sync_with_stdio(false);

    int N, Answer = 0;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int Sx, Sy;
        cin >> Sx >> Sy;

        for (int j = 0; j < 10; ++j)
            for (int k = 0; k < 10; ++k)
                Board[Sx+j][Sy+k] = true;
    }

    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j)
            if (Board[i][j])
                ++Answer;

    cout << Answer << '\n';

    return 0;
}
