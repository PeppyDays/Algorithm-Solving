def place(n: int, queen: list=[]):
    rs = len(queen)
    ret = 0

    if rs == n:
        return 1

    for cs in range(n):
        is_safe = True

        for re, ce in enumerate(queen):
            if cs == ce or abs(re - rs) == abs(ce - cs):
                is_safe = False
                break

        if is_safe:
            ret += place(n, queen + [cs])

    return ret


print(place(int(input().strip())))
