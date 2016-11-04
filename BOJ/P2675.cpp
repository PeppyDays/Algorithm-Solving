#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int t, r;
string s;
string answer;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        cin >> r >> s;
        answer = "";
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < r; j++)
                answer += s[i];
        }
        cout << answer << '\n';
    }

    return 0;
}

