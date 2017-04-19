#include <iostream>
using namespace std;

const pair<int, int> block_types[4][3] = {
        {{0, 0}, {0, 1}, {1, 0}},
        {{0, 0}, {1, 0}, {1, 1}},
        {{0, 0}, {1, 0}, {1, -1}},
        {{0, 0}, {0, 1}, {1, 1}},
};

int H, W;
bool Board[20][20];

bool setBlock(int x, int y, int type_no);
bool unsetBlock(int x, int y, int type_no);
int coverBoard();

int main() {
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        cin >> H >> W;

        int block_cnt = 0;
        for (int i = 0; i < H; i++) {
            string row;
            cin >> row;

            for (int j = 0; j < W; j++) {
                Board[i][j] = (row[j] == '.');
                if (Board[i][j])
                    ++block_cnt;
            }
        }

        if (block_cnt % 3 != 0) {
            cout << 0 << '\n';
            continue;
        }

        int Answer = coverBoard();

        cout << Answer << '\n';
    }

    return 0;
}

bool setBlock(int x, int y, int type_no) {
    bool can_set = true;
    int block_x, block_y;

    for (int i = 0; i < 3; i++) {
        block_x = x + block_types[type_no][i].first;
        block_y = y + block_types[type_no][i].second;

        if (block_x < 0 || block_x >= H || block_y < 0 || block_y >= W || !Board[block_x][block_y]) {
            can_set = false;
            break;
        }
    }

    if (!can_set)
        return false;

    for (int i = 0; i < 3; i++) {
        block_x = x + block_types[type_no][i].first;
        block_y = y + block_types[type_no][i].second;
        Board[block_x][block_y] = false;
    }

    return true;
}

bool unsetBlock(int x, int y, int type_no) {
    int block_x, block_y;

    for (int i = 0; i < 3; i++) {
        block_x = x + block_types[type_no][i].first;
        block_y = y + block_types[type_no][i].second;
        Board[block_x][block_y] = true;
    }

    return true;
}

int coverBoard() {
    int x, y;

    for (x = 0; x < H; ++x) {
        for (y = 0; y < W; y++) {
            if (Board[x][y])
                break;
        }

        if (y != W)
            break;
    }

    if (x == H && y == W)
        return 1;

    int ret = 0;

    for (int i = 0; i < 4; i++) {
        if (setBlock(x, y, i)) {
            ret += coverBoard();
            unsetBlock(x, y, i);
        }
    }

    return ret;
}
