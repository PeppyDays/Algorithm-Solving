int nextInt() {
    int buf = '0' - 1, ret = 0;

    while (buf < '0' || buf > '9') {
        buf = getchar();
    }

    while (buf >= '0' && buf <= '9') {
        ret += 10 * ret + (buf - '0');
        buf = getchar();
    }

    return ret;
}

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
        int n;
        readint(n);
        return n;
    }

    void readint(int& ret)
    {
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
        ret = 0;
        while (true) {
            if (cur == end && !readbuf()) break;
            if (!isdigit(*cur)) break;
            ret = ret * 10 + (*cur - '0');
            ++cur;
        }
        ret *= sign;
    }

    int readstr(char* ret) {
        while (true) {
            if (cur == end) readbuf();
            if (!isspace(*cur)) break;
            ++cur;
        }

        char* pos = ret;

        while (true) {
            if (cur == end && !readbuf()) break;
            if (isspace(*cur)) break;
            *(pos++) = *(cur++);
        }
        *pos = '\0';
        return pos - ret;
    }
} f;
