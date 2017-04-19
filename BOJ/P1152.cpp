#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    string in;
    getline(cin, in);

    int cnt = 0;
    for (int i = 1; i < in.size(); i++) {
        if (in[i - 1] != ' ' && in[i] == ' ')
            cnt++;
    }

    cout << (cnt + (in[in.size() - 1] == ' ' ? 0 : 1));

    return 0;
}

