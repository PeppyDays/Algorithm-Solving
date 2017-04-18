#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    string r = to_string(a * b * c);

    for (int i = 0; i < 10; i++)
        cout << count(r.begin(), r.end(), (char)(i + 48)) << '\n';

    return 0;
}

