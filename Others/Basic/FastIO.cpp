#include <cstdio>
using namespace std;


class FastIO {
    int fd, bufsz;
    char *buf, *cur, *end;
public:
    FastIO(int _fd = 0, int _bufsz = 1 << 20) : fd(_fd), bufsz(_bufsz) {
        buf = cur = end = new char[bufsz];
    }
    ~FastIO() {
        delete[] buf;
    }
    bool readbuf() {
        cur = buf;
        end = buf + bufsz;
        while (true) {
            size_t res = fread(cur, sizeof(char), end - cur, stdin);
            if (res == 0) break;
            cur += res;
        }
        end = cur;
        cur = buf;
        return buf != end;
    }
    int readint() {
        while (true) {
            if (cur == end) readbuf();
            if (isdigit(*cur) || *cur == '-') break;
            ++cur;
        }
        int sign = 1;
        if (*cur == '-') {
            sign = -1;
            ++cur;
        }
        int ret = 0;
        while (true) {
            if (cur == end && !readbuf()) break;
            if (!isdigit(*cur)) break;
            ret = ret * 10 + (*cur - '0');
            ++cur;
        }
        return sign * ret;
    }
};

//    FastIO fio;
//    int n = fio.readint();
















char in[1 << 20];
const char* o;

void getIn() {
    o = in;
    in[fread(in, 1, sizeof(in) - 4, stdin)] = '\n';
}

int nextInt() {
    int ret = 0;
    bool sign = true;

    while ((*o < '0' || *o > '9') && *o != '-') ++o;
    if (*o == '-') { sign = false; o++; };
    while (*o >= '0' && *o <= '9') ret = 10 * ret + *o++ - '0';

    return sign ? ret : -ret;
}

int main() {
    getIn();

    int T = nextInt();

    return 0;
}