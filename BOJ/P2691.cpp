#include <cstdio>
#include <string>
using namespace std;



class Barcode {
public:
    char code[95];
    char codeL[6][7];
    char codeR[6][7];

    void setCode(int i, char c) {
        code[i] = c;
    }

    void setCodeLR() {
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 7; ++j)
                codeL[i][j] = code[3 + i + 7 * j];

        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 7; ++j)
                codeR[i][j] = code[50 + i + 7 * j];
    }

    void reverse() {
        char temp[95];
        for (int i = 0; i < 95; ++i) temp[i] = code[i];
        for (int i = 0; i < 95; ++i) code[i] = temp[94 - i];
    }


};

char getCode();


int main() {
    int T;
    scanf("%d", &T);

    Barcode barcode;

    while (T--) {
        for (int i = 0; i < 95; ++i)
            barcode.setCode(i, getCode());

        // Non-reverse
        barcode.setCodeLR();


    }

    return 0;
}


char getCode() {
    char o = getchar();
    while (o != '0' && o != '1' && o !='?') o = getchar();
    return o;
}
