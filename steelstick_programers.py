answer = 0
arrangement = '()(((()())(())()))(())'
stack = []
i = 0
while True:
    if i == len(arrangement):
        break;
    print(stack)
    print("arrangement : ", arrangement[i])
    print("index number : ", i)
    if (i <= len(arrangement)-2) and (arrangement[i] + arrangement[i+1] == '()'):
        answer += len(stack)
        i += 1
        if i == len(arrangement):
            break
    elif arrangement[i] == '(':
        stack.append('(')
    elif arrangement[i] == ')':
        answer += 1
        stack.pop()
    i += 1
print(answer)
