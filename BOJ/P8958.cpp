#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        string in;
        cin >> in;

        int total = 0;
        int cnt = 0;

        for (int i = 0; i < in.size(); i++) {
            if (in[i] == 'O') {
                cnt++;
                total += cnt;
            }
            else {
                cnt = 0;
            }
        }

        cout << total << '\n';
    }

    return 0;
}

