import sys
from itertools import combinations
N = int(sys.stdin.readline())
L = []
for x in range(N):
  L.append(list(map(lambda n: int(n), sys.stdin.readline().rstrip().split(' '))))
# for x in L:
#   print(x)
# sys.exit(0)
# SWITCHS = [] 
# for x in range(10):
#   SWITCHS += [x] * 3
SWITCHS = [0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9]
LINK = [
  [0, 1, 2],
  [3, 7, 9, 11],
  [4, 10, 14, 15],
  [0, 4, 5, 6, 7],
  [6, 7, 8, 10, 12],
  [0, 2, 14, 15],
  [3, 14, 15],
  [4, 5, 7, 14, 15],
  [1, 2, 3, 4, 5],
  [3, 4, 5, 9, 13]
]

def push(l, sList):
  result = True
  for s in sList:
    cList = LINK[SWITCHS[s]]
    for c in cList:
      l[c] = l[c] + 3 if l[c] != 12 else 0
  for x in l:
    if (x != 12):
      result = False
      break
  return result

def solution(l):
  result = 99999
  for j in range(1, 31):
    for i in combinations([x for x in range(30)], j):
      ret = push(list(l), list(i))
      if ret:
        result = j
  return result if result != 99999 else -1

for x in range(N):
  print(solution(list(L[x])))