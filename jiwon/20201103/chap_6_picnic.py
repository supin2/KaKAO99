import sys


C = int(sys.stdin.readline().rstrip())
RESULT = set([])
# setList , 0 , "", []
def foo(lst, destLen, selected, results):
  # print(lst)
  # print(lst, destLen, selected, results)
  if len(selected) == destLen:
    RESULT.add(''.join(sorted(selected)))
    return
  if len(lst) == 0: 
    return
  for x in range(len(lst)):
    if (lst[x][0] not in results) and (lst[x][1] not in results):
      foo(lst[x+1:], destLen, selected + lst[x][2], results + [lst[x][0], lst[x][1]])
    else:
      foo(lst[x+1:], destLen, selected, results)
    

resultList = []
problemList = []
for c in range(C):
  N, M = list(map(lambda n: int(n), sys.stdin.readline().rstrip().split(' ')))
  problemList.append([N, M, list(map(lambda n: int(n), sys.stdin.readline().rstrip().split(' ')))])
for c in range(C):
  FRIEND = []
  for x in range(0, problemList[c][1] * 2, 2):
    FRIEND.append([problemList[c][2][x], problemList[c][2][x+1], str(x//2)])
  foo(FRIEND, problemList[c][0]//2, "", [])  
  # print('result', RESULT)
  resultList.append(len(RESULT))
  RESULT = set([])
  
for x in resultList:
  print(x)