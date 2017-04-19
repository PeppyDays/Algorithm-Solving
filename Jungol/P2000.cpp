#include <iostream>
#include <limits>
using namespace std;

static int INF = numeric_limits<int>::max();

int N, W;
int coins[10];
int cache[64001];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> coins[i];
    cin >> W;

    cache[0] = 0;
    int sub_answer = 0;

    for (int i = 1; i <= W; ++i) {
        sub_answer = INF;
        for (int j = 0; j < N; ++j) {
            if (i >= coins[j] && cache[i - coins[j]] != -1)
                sub_answer = min(sub_answer, 1 + cache[i - coins[j]]);
        }

        cache[i] = ((sub_answer == INF)? -1 : sub_answer);
    }

    cout << ((cache[W] == -1)? "impossible" : to_string(cache[W]));

    return 0;
}
