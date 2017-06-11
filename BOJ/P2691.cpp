#include <cstdio>
using namespace std;

const char patternL[10][7] = {
    {'0', '0', '0', '1', '1', '0', '1'},
    {'0', '0', '1', '1', '0', '0', '1'},
    {'0', '0', '1', '0', '0', '1', '1'},
    {'0', '1', '1', '1', '1', '0', '1'},
    {'0', '1', '0', '0', '0', '1', '1'},
    {'0', '1', '1', '0', '0', '0', '1'},
    {'0', '1', '0', '1', '1', '1', '1'},
    {'0', '1', '1', '1', '0', '1', '1'},
    {'0', '1', '1', '0', '1', '1', '1'},
    {'0', '0', '0', '1', '0', '1', '1'},
};

const char patternR[10][7] = {
    {'1', '1', '1', '0', '0', '1', '0'},
    {'1', '1', '0', '0', '1', '1', '0'},
    {'1', '1', '0', '1', '1', '0', '0'},
    {'1', '0', '0', '0', '0', '1', '0'},
    {'1', '0', '1', '1', '1', '0', '0'},
    {'1', '0', '0', '1', '1', '1', '0'},
    {'1', '0', '1', '0', '0', '0', '0'},
    {'1', '0', '0', '0', '1', '0', '0'},
    {'1', '0', '0', '1', '0', '0', '0'},
    {'1', '1', '1', '0', '1', '0', '0'}
};

const char patternS[3] = {'1', '0', '1'};
const char patternE[3] = {'1', '0', '1'};
const char patternM[5] = {'0', '1', '0', '1', '0'};

class Barcode {
public:
    char code[95];
    char codeL[6][7];
    char codeR[6][7];
    char codeS[3];
    char codeM[5];
    char codeE[3];
    int matchL[6];
    int matchR[6];

    void setCode(int i, char c) {
        code[i] = c;
    }

    void setCodeLR() {
        int codeIdx = 0;

        for (int i = 0; i < 3; ++i)
            codeS[i] = code[codeIdx++];

        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 7; ++j)
                codeL[i][j] = code[codeIdx++];

        for (int i = 0; i < 5; ++i)
            codeM[i] = code[codeIdx++];

        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 7; ++j)
                codeR[i][j] = code[codeIdx++];

        for (int i = 0; i < 3; ++i)
            codeE[i] = code[codeIdx++];
    }

    void reverse() {
        char temp[95];
        for (int i = 0; i < 95; ++i) temp[i] = code[i];
        for (int i = 0; i < 95; ++i) code[i] = temp[94 - i];
    }

    bool setMatchSME() {
        for (int i = 0; i < 3; ++i) {
            if (codeS[i] != '?' && codeS[i] != patternS[i])
                return false;
        }

        for (int i = 0; i < 5; ++i) {
            if (codeM[i] != '?' && codeM[i] != patternM[i])
                return false;
        }

        for (int i = 0; i < 3; ++i) {
            if (codeE[i] != '?' && codeE[i] != patternE[i])
                return false;
        }

        return true;
    }

    bool setMatchLR() {
        int matchIdx, idx, i, j;

        for (idx = 0; idx < 6; ++idx) {
            matchIdx = 0;

            for (i = 0; i < 10; ++i) {
                for (j = 0; j < 7; ++j) {
                    if (codeL[idx][j] != '?' && codeL[idx][j] != patternL[i][j])
                        break;
                }

                if (j == 7)
                    matchIdx |= (1 << i);
            }

            if (matchIdx == 0)
                return false;

            matchL[idx] = matchIdx;
        }

        for (idx = 0; idx < 6; ++idx) {
            matchIdx = 0;

            for (i = 0; i < 10; ++i) {
                for (j = 0; j < 7; ++j) {
                    if (codeR[idx][j] != '?' && codeR[idx][j] != patternR[i][j])
                        break;
                }

                if (j == 7)
                    matchIdx |= (1 << i);
            }

            if (matchIdx == 0)
                return false;

            matchR[idx] = matchIdx;
        }

        return true;
    }

    bool checksum(int l0, int l1, int l2, int l3, int l4, int l5, int r0, int r1, int r2, int r3, int r4, int r5) {
        int check = (3 * (l0 + l2 + l4 + r0 + r2 + r4) + (l1 + l3 + l5 + r1 + r3)) % 10;
        if (!check)
            return r5 == 0;
        else
            return r5 == (10 - check);
    }
};

char getCode();
int strcmp(char* u, char* v);

int main() {
    freopen("resources/input.in", "r", stdin);
    int T;
    scanf("%d", &T);

    Barcode barcode;
    char retNon[9][12];
    char retRev[9][12];
    int retNonIdx, retRevIdx;

    while (T--) {
        for (int i = 0; i < 95; ++i)
            barcode.setCode(i, getCode());

        // Non-reverse
        barcode.setCodeLR();
        retNonIdx = 0;

        if (barcode.setMatchSME() && barcode.setMatchLR()) {
            for (int l0 = 0; l0 < 10; ++l0) {
                if (!(barcode.matchL[0] & (1 << l0))) continue;

                for (int l1 = 0; l1 < 10; ++l1) {
                    if (!(barcode.matchL[1] & (1 << l1))) continue;

                    for (int l2 = 0; l2 < 10; ++l2) {
                        if (!(barcode.matchL[2] & (1 << l2))) continue;

                        for (int l3 = 0; l3 < 10; ++l3) {
                            if (!(barcode.matchL[3] & (1 << l3))) continue;

                            for (int l4 = 0; l4 < 10; ++l4) {
                                if (!(barcode.matchL[4] & (1 << l4))) continue;

                                for (int l5 = 0; l5 < 10; ++l5) {
                                    if (!(barcode.matchL[5] & (1 << l5))) continue;

                                    for (int r0 = 0; r0 < 10; ++r0) {
                                        if (!(barcode.matchR[0] & (1 << r0))) continue;

                                        for (int r1 = 0; r1 < 10; ++r1) {
                                            if (!(barcode.matchR[1] & (1 << r1))) continue;

                                            for (int r2 = 0; r2 < 10; ++r2) {
                                                if (!(barcode.matchR[2] & (1 << r2))) continue;

                                                for (int r3 = 0; r3 < 10; ++r3) {
                                                    if (!(barcode.matchR[3] & (1 << r3))) continue;

                                                    for (int r4 = 0; r4 < 10; ++r4) {
                                                        if (!(barcode.matchR[4] & (1 << r4))) continue;

                                                        for (int r5 = 0; r5 < 10; ++r5) {
                                                            if (!(barcode.matchR[5] & (1 << r5))) continue;
                                                            if (!barcode.checksum(l0, l1, l2, l3, l4, l5, r0, r1, r2, r3, r4, r5)) continue;

                                                            retNon[retNonIdx][0] = l0 + '0';
                                                            retNon[retNonIdx][1] = l1 + '0';
                                                            retNon[retNonIdx][2] = l2 + '0';
                                                            retNon[retNonIdx][3] = l3 + '0';
                                                            retNon[retNonIdx][4] = l4 + '0';
                                                            retNon[retNonIdx][5] = l5 + '0';
                                                            retNon[retNonIdx][6] = r0 + '0';
                                                            retNon[retNonIdx][7] = r1 + '0';
                                                            retNon[retNonIdx][8] = r2 + '0';
                                                            retNon[retNonIdx][9] = r3 + '0';
                                                            retNon[retNonIdx][10] = r4 + '0';
                                                            retNon[retNonIdx][11] = r5 + '0';
                                                            ++retNonIdx;

                                                            if (retNonIdx >= 9) break;
                                                        }

                                                        if (retNonIdx >= 9) break;
                                                    }

                                                    if (retNonIdx >= 9) break;
                                                }

                                                if (retNonIdx >= 9) break;
                                            }

                                            if (retNonIdx >= 9) break;
                                        }

                                        if (retNonIdx >= 9) break;
                                    }

                                    if (retNonIdx >= 9) break;
                                }

                                if (retNonIdx >= 9) break;
                            }

                            if (retNonIdx >= 9) break;
                        }

                        if (retNonIdx >= 9) break;
                    }

                    if (retNonIdx >= 9) break;
                }

                if (retNonIdx >= 9) break;
            }
        }

        // Reverse
        barcode.reverse();
        barcode.setCodeLR();
        retRevIdx = 0;

        if (barcode.setMatchSME() && barcode.setMatchLR()) {
            for (int l0 = 0; l0 < 10; ++l0) {
                if (!(barcode.matchL[0] & (1 << l0))) continue;

                for (int l1 = 0; l1 < 10; ++l1) {
                    if (!(barcode.matchL[1] & (1 << l1))) continue;

                    for (int l2 = 0; l2 < 10; ++l2) {
                        if (!(barcode.matchL[2] & (1 << l2))) continue;

                        for (int l3 = 0; l3 < 10; ++l3) {
                            if (!(barcode.matchL[3] & (1 << l3))) continue;

                            for (int l4 = 0; l4 < 10; ++l4) {
                                if (!(barcode.matchL[4] & (1 << l4))) continue;

                                for (int l5 = 0; l5 < 10; ++l5) {
                                    if (!(barcode.matchL[5] & (1 << l5))) continue;

                                    for (int r0 = 0; r0 < 10; ++r0) {
                                        if (!(barcode.matchR[0] & (1 << r0))) continue;

                                        for (int r1 = 0; r1 < 10; ++r1) {
                                            if (!(barcode.matchR[1] & (1 << r1))) continue;

                                            for (int r2 = 0; r2 < 10; ++r2) {
                                                if (!(barcode.matchR[2] & (1 << r2))) continue;

                                                for (int r3 = 0; r3 < 10; ++r3) {
                                                    if (!(barcode.matchR[3] & (1 << r3))) continue;

                                                    for (int r4 = 0; r4 < 10; ++r4) {
                                                        if (!(barcode.matchR[4] & (1 << r4))) continue;

                                                        for (int r5 = 0; r5 < 10; ++r5) {
                                                            if (!(barcode.matchR[5] & (1 << r5))) continue;
                                                            if (!barcode.checksum(l0, l1, l2, l3, l4, l5, r0, r1, r2, r3, r4, r5)) continue;

                                                            retRev[retRevIdx][0] = l0 + '0';
                                                            retRev[retRevIdx][1] = l1 + '0';
                                                            retRev[retRevIdx][2] = l2 + '0';
                                                            retRev[retRevIdx][3] = l3 + '0';
                                                            retRev[retRevIdx][4] = l4 + '0';
                                                            retRev[retRevIdx][5] = l5 + '0';
                                                            retRev[retRevIdx][6] = r0 + '0';
                                                            retRev[retRevIdx][7] = r1 + '0';
                                                            retRev[retRevIdx][8] = r2 + '0';
                                                            retRev[retRevIdx][9] = r3 + '0';
                                                            retRev[retRevIdx][10] = r4 + '0';
                                                            retRev[retRevIdx][11] = r5 + '0';
                                                            ++retRevIdx;

                                                            if (retRevIdx >= 9) break;
                                                        }

                                                        if (retRevIdx >= 9) break;
                                                    }

                                                    if (retRevIdx >= 9) break;
                                                }

                                                if (retRevIdx >= 9) break;
                                            }

                                            if (retRevIdx >= 9) break;
                                        }

                                        if (retRevIdx >= 9) break;
                                    }

                                    if (retRevIdx >= 9) break;
                                }

                                if (retRevIdx >= 9) break;
                            }

                            if (retRevIdx >= 9) break;
                        }

                        if (retRevIdx >= 9) break;
                    }

                    if (retRevIdx >= 9) break;
                }

                if (retRevIdx >= 9) break;
            }
        }

        int retNonPtr = 0, retRevPtr = 0, retPrintCnt = 0;
        printf("%d\n", (retNonIdx + retRevIdx) >= 9 ? 9 : (retNonIdx + retRevIdx));
        while (retNonPtr < retNonIdx && retRevPtr < retRevIdx && retPrintCnt < 8) {
            if (strcmp(retNon[retNonPtr], retRev[retRevPtr]) > 0) {
                for (int i = 0; i < 12; ++i) {
                    printf("%c", retRev[retRevPtr][i]);
                }
                printf("\n");
                ++retRevPtr;
            }
            else if (strcmp(retNon[retNonPtr], retRev[retRevPtr]) < 0) {
                for (int i = 0; i < 12; ++i) {
                    printf("%c", retNon[retNonPtr][i]);
                }
                printf("\n");
                ++retNonPtr;
            }
            else {
                for (int i = 0; i < 12; ++i) {
                    printf("%c", retNon[retNonPtr][i]);
                }
                printf("\n");
                ++retNonPtr;
                ++retRevPtr;
            }
            ++retPrintCnt;
        }
        while (retNonPtr < retNonIdx && retPrintCnt < 8) {
            for (int i = 0; i < 12; ++i) {
                printf("%c", retNon[retNonPtr][i]);
            }
            printf("\n");
            ++retNonPtr;
            ++retPrintCnt;
        }
        while (retRevPtr < retRevIdx && retPrintCnt < 8) {
            for (int i = 0; i < 12; ++i) {
                printf("%c", retRev[retRevPtr][i]);
            }
            printf("\n");
            ++retRevPtr;
            ++retPrintCnt;
        }
    }

    return 0;
}

char getCode() {
    char o = getchar();
    while (o != '0' && o != '1' && o !='?') o = getchar();
    return o;
}

int strcmp(char* u, char* v) {
    for (int i = 0; i < 12; ++i) {
        if (u[i] > v[i])
            return 1;
        else if (v[i] > u[i])
            return -1;
    }

    return 0;
}