from copy import deepcopy
from itertools import permutations
from sys import stdin

def rotate(r, c, s, arr):
    for n in range(s, 0, -1):
        tmp  = arr[r-n][c+n]
        arr[r-n][c-n+1:c+n+1] = arr[r-n][c-n:c+n]
        for col in range(r-n, r+n):
            arr[col][c-n] = arr[col+1][c-n]
        arr[r+n][c-n:c+n] = arr[r+n][c-n+1:c+n+1]
        for col in range(r+n, r-n, -1):
            arr[col][c+n] = arr[col-1][c+n]
        arr[r-n+1][c+n] = tmp
    return arr

n, m, k = [int(x) for x in input().rstrip().split()]
origin_arr = []
for _ in range(n):
    origin_arr.append([int(x) for x in input().rstrip().split()])
ops = []
for _ in range(k):
    r, c, s = [int(x) for x in input().rstrip().split()]
    r, c = r-1, c-1
    ops.append((r,c,s))

answer = 100*50*50
results = {}
for op in permutations(ops):
    if op not in results:
        arr = deepcopy(origin_arr)
        
        for r,c,s in op:
            arr = rotate(r, c, s, arr)

        results[op] = min(map(sum, arr))
    
print(min(results.values()))

