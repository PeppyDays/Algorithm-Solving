code = ['%20', '%21', '%24', '%28', '%29', '%2a', '%25']
value = [' ', '!', '$', '(', ')', '*', '%']

for _ in range(int(input())):
    line = input()

    for c, v in zip(code, value):
        line = line.replace(c, v)

    print(line)
