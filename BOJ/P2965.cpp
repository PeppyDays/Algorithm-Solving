
#include <iostream>
#include <algorithm>
using namespace std;

int result = 0;

void test(int a, int b, int c) {
    if (b - a < c - b) {
        a = b;
        b = b + 1;
    }
    else if (b - a > c - b) {
        c = b;
        b = b - 1;
    }
    else if (b - a == 1 && c - b == 1) {
        cout << result;
        return;
    }

    result++;
    test(a, b, c);

    return;
}

int main() {
    freopen("resources/input.in", "r", stdin);
    ios_base::sync_with_stdio(false);

    int A, B, C;
    cin >> A >> B >> C;

    test(A, B, C);

    // cout << (max(C - B, B - A) - 1);

    // while (A != B && B != C) {
    //     int delta_ab = B - A;
    //     int delta_bc = C - B;

    //     if (delta_ab > delta_bc) {
    //         C = A + 1;
    //         swap(B, C);
    //     }
    //     else {
    //         A = B + 1;
    //         swap(A, B);
    //     }

    //     ++loop_cnt;
    // }

    // cout << (loop_cnt - 1);

    return 0;
}
