#include <stdio.h>
#include <algorithm>
using namespace std;

typedef pair<int, int> couple;
const int MaxN = 1000;

int n, m;
int map[MaxN][MaxN];
couple cnt[MaxN][MaxN];

int square(int x, int y);

int main() {
    scanf("%d %d", &n, &m);
    char buf[MaxN];
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        for (int j = 0; j < m; ++j) {
            map[i][j] = buf[j] - '0';
        }
    }

    for (int i = 0; i < n; ++i)
        cnt[i][m - 1].first = map[i][m - 1];

    for (int i = 0; i < n; ++i) {
        for (int j = m - 2; j >= 0; --j) {
            if (map[i][j] == 0)
                cnt[i][j].first = 0;
            else
                cnt[i][j].first = cnt[i][j + 1].first + map[i][j];
        }
    }

    for (int i = 0; i < m; ++i)
        cnt[n - 1][i].second = map[n - 1][i];

    for (int i = 0; i < m; ++i) {
        for (int j = n - 2; j >= 0; --j) {
            if (map[j][i] == 0)
                cnt[j][i].second = 0;
            else
                cnt[j][i].second = cnt[j + 1][i].second + map[j][i];
        }
    }

    int answer = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == 1)
                answer = max(answer, square(i, j));
        }
    }

    printf("%d\n", answer);

    return 0;
}

int square(int x, int y) {
    int len = min(cnt[x][y].first, cnt[x][y].second);
    for (int c = 1; c <= len; c++) {
        int subLen = min(cnt[x + c][y + c].first, cnt[x + c][y + c].second);
        len = min(len, subLen + c);
    }

    return len * len;
}
