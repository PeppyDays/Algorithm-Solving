#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

char* intToString(int n) {
    char rev[10], ret[10], idx = 0;

    while (n > 0) {
        rev[idx++] = n % 10;
        n /= 10;
    }

    for (int i = idx - 1; i >= 0; --i)
        ret[idx - i - 1] = rev[i];

    char* r = ret;
    return r;
}


int main() {
    int n = 532;

    char buf[256];
    // sprintf(buf, "%d", n);
    // string s = string(buf);

    printf("%s\n", string(intToString(n)).c_str());


    // cout << s << endl;

    return 0;
}

