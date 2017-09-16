import sys


patternL = {
    '0001101': 0,
    '0011001': 1,
    '0010011': 2,
    '0111101': 3,
    '0100011': 4,
    '0110001': 5,
    '0101111': 6,
    '0111011': 7,
    '0110111': 8,
    '0001011': 9
}

patternR = {
    '1110010': 0,
    '1100110': 1,
    '1101100': 2,
    '1000010': 3,
    '1011100': 4,
    '1001110': 5,
    '1010000': 6,
    '1000100': 7,
    '1001000': 8,
    '1110100': 9
}


def readline():
    return sys.stdin.readline()


def findPattern(code, lr):
    if lr == 'L':






T = int(readline())

for t in range(T):
    code_all = readline().strip()
    code_all += readline().strip()
    code_left = [code_all[3:10], code_all[10:17], code_all[17:24], code_all[24:31], code_all[31:38], code_all[38:45]]
    code_right = [code_all[50:57], code_all[57:64], code_all[64:71], code_all[71:78], code_all[78:85], code_all[85:92]]

    inverse_code_all = code_all[::-1]
    inverse_code_left = [inverse_code_all[3:10], inverse_code_all[10:17], inverse_code_all[17:24], inverse_code_all[24:31], inverse_code_all[31:38], inverse_code_all[38:45]]
    inverse_code_right = [inverse_code_all[50:57], inverse_code_all[57:64], inverse_code_all[64:71], inverse_code_all[71:78], inverse_code_all[78:85], inverse_code_all[85:92]]

    # Check if the code exists in the pattern
    # Check if the reversed code exists in the pattern
    is_code_ok = True
    is_inverse_code_ok = True

    for code in code_left:
        if code not in patternL.keys():
            is_code_ok = False
            break

    for code in code_right:
        if code not in patternR.keys():
            is_code_ok = False
            break

    for code in inverse_code_left:
        if code not in patternL.keys():
            is_code_ok = False
            break

    for code in inverse_code_right:
        if code not in patternR.keys():
            is_code_ok = False
            break

    print(is_code_ok, is_inverse_code_ok)







