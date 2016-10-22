#include <iostream>
#include <cstring>
using namespace std;

#define MaxN 201
#define INF 1000000005

int n, m, k;
int bino[MaxN][MaxN];

string kth(int n, int m, int skip);
void calcBino();


int main() {
    ios_base::sync_with_stdio(false);
    freopen("/Users/donald/ClionProjects/AlgorithmSolving/input.in", "r", stdin);

    int T;
    cin >> T;

    calcBino();

    while (T--) {
        cin >> n >> m >> k;

        calcBino();
        cout << kth(n, m, k - 1) << '\n';
    }

    return 0;
}

string kth(int n, int m, int skip) {
    if (n == 0)
        return string(m, 'o');

    if (skip < bino[n + m -1][n - 1])
        return "-" + kth(n - 1, m, skip);

    return "o" + kth(n, m - 1, skip - bino[n + m - 1][n - 1]);
}

void calcBino() {
    memset(bino, 0, sizeof(bino));
    for (int i = 0; i <= 200; i++) {
        bino[i][0] = bino[i][i] = 1;
        for (int j = 1; j < i; j++) {
            bino[i][j] = min(INF, bino[i - 1][j - 1] + bino[i - 1][j]);
        }
    }

    return;
}