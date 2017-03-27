#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int dx[8] = { -1, -1, -1,  1,  1,  1,  0,  0};
const int dy[8] = { -1,  0,  1, -1,  0,  1, -1,  1};

string Word;
char Board[5][5];
int Cache[5][5][11];

bool hasWord(int x, int y, int pos);

int main() {
    freopen("/Users/donald/Documents/workspace/AlgorithmSolving/AlgorithmSolving/input.in", "r", stdin);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        for (int i = 0; i < 5; ++i) {
            string token;
            cin >> token;

            for (int j = 0; j < 5; ++j) {
                Board[i][j] = token[j];
            }
        }

        int N;
        cin >> N;

        while (N--) {
            memset(Cache, -1, sizeof(Cache));

            string result = "NO";
            cin >> Word;

            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (hasWord(i, j, 0)) {
                        result = "YES";
                        break;
                    }
                }
            }

            cout << Word << ' ' << result << '\n';
        }
    }

    return 0;
}

bool hasWord(int x, int y, int pos) {
    if (x < 0 || x >= 5 || y < 0 || y >= 5)
        return false;

    if (Board[x][y] != Word[pos])
        return false;

    if (Word.size() == pos + 1)
        return true;

    if (Cache[x][y][pos] != -1)
        return Cache[x][y][pos];

    bool ret = false;

    for (int d = 0; d < 8; ++d) {
        if (hasWord(x + dx[d], y + dy[d], pos + 1)) {
            ret = true;
            break;
        }
    }

    Cache[x][y][pos] = int(ret);
    return ret;
}
