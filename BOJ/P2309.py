dwarf = []

for _ in range(9):
    dwarf.append(int(input()))

diff = sum(dwarf) - 100
dwarf.sort()

finish = False

for i, first in enumerate(dwarf[:-1]):
    for second in dwarf[i+1:]:
        if first + second == diff:
            print('\n'.join([str(v) for v in dwarf if v != first and v != second]))
            finish = True
            break

        if first + second > diff:
            break

    if finish:
        break
