en_to_no = {
    'zero': 0,
    'one': 1,
    'two': 2,
    'three': 3,
    'four': 4,
    'five': 5,
    'six': 6,
    'seven': 7,
    'eight': 8,
    'nine': 9,
    'ten': 10,
}


def calculate(a_no, op, b_no):
    if op == '+':
        result = a_no + b_no
    elif op == '*':
        result = a_no * b_no
    elif op == '-':
        result = a_no - b_no
    else:
        if b_no is 0:
            result = -1
        else:
            result = a_no / b_no

    return result


def check_result_string(c_en):
    for en in [k for k in en_to_no.keys() if len(k) is len(c_en)]:
        if not set(en) - set(c_en):
            return en_to_no[en]

    return None


for _ in range(int(input())):
    a_en, op, b_en, _, c_en = input().split()
    a_no, b_no = en_to_no[a_en], en_to_no[b_en]

    op_result = calculate(a_no, op, b_no)

    if op_result < 0 or op_result > 10:
        print('No')
        continue

    c_no = check_result_string(c_en)

    if op_result == c_no:
        print('Yes')
    else:
        print('No')
