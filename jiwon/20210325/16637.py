import itertools 
def check(l):
    ret = True
    for x in range(len(l)-1):
        ret = ret and (l[x + 1] - l[x] > 1)
    return ret

def cal(a, b, op):
    if op == '+':
        return a + b
    elif op == '-':
        return a - b
    else:
        return a * b

def calList(l, p):
    for x in p:
        n = 2 * x + 1
        l[n - 1] = cal(l[n - 1], l[n + 1], l[n])
        l[n] = '!'
        l[n + 1] = '!'
    while '!' in l:
        l.remove('!')
    while len(l) > 1:
        l[0] = cal(l[0], l[2], l[1])
        del l[1]
        del l[1]
    return l[0]

def solution(L):
    MAX = -2147483646
    for x in range(N_OP + 1):
        combi = itertools.combinations(range(N_OP), x)
        for y in list(combi):
            if (check(list(y))):
                temp = calList(list(L), list(y))
                MAX = temp if temp > MAX else MAX
    return MAX

N = int(input())
N_OP = (N - 1) // 2
INPUT = []
i = 0
for x in input():
    if i % 2 == 0:
        INPUT.append(int(x))
    else:
        INPUT.append(x)
    i += 1

print(solution(INPUT))