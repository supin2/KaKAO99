# Link
# https://algospot.com/judge/problem/read/SORTGAME

# 문제
# 중복이 없는 정수 수열이 주어진다. 이 때, 우리는 이 수열의 임의의 구간을 선택해서 해당 구간을 뒤집을 수 있다.
# 이 뒤집기 연산을 통해 전체 수열을 정렬하고 싶다. 그런데, 같은 수열도 두 가지 이상의 방식으로 정렬할 수 있다.
# 예를 들어 3 4 1 2 는, 3 4 와 1 2 를 각각 뒤집어 4 3 2 1 을 만든 뒤,
# 전체를 뒤집어 정렬할 수도 있지만, 4 1 2 를 먼저 뒤집고, 3 2 1 을 다시 뒤집으면 두 번만의 연산으로 정렬할 수도 있다.

# 정렬을 위해 뒤집기 연산을 최소 몇 번 해야 하는지를 계산하는 프로그램을 작성하라.

# 입력
# 입력의 첫 줄에는 테스트 케이스의 수 C (<= 1000) 이 주어진다. 
# 각 테스트 케이스의 첫 줄에는 수열의 길이 N (1 <= N <= 8) 이 주어진다.
# 다음 줄에 N개의 정수로 각 수열의 원소들이 순서대로 주어진다. 한 수열에 같은 수가 두 번 출현하지 않는다고 가정해도 좋다.
# 모든 수는 1부터 1백만 사이의 정수이다.

# 출력
# 각 테스트 케이스마다 입력을 정렬하기 위해 필요한 최소 뒤집기 연산의 수를 출력한다.
class NumSeq:
  def __init__(self, key):
    self.key = key
    self.distance = -1
    self.discovered = True
  def setDistance(self, d):
    self.distance = d
  def getDistance(self):
    return self.distance
  def setDiscovered(self, d):
    self.discovered = d
  def getDiscovered(self):
    return self.discovered
  def getKey(self):
    return self.key

dict = {}

def reverseString(str, start, end):
  pre = str[:start]
  post = str[end+1:]
  return pre + ''.join(reversed(list(str[start: end+1]))) + post


# Start

def solution(given, sortedStr):
  queue = []
  queue.append(sortedStr)
  dict[sortedStr] = NumSeq(sortedStr)
  dict[sortedStr].setDistance(0)

  currNode = ''
  while(given != currNode):
    # print('currNode', currNode, given)
    if (len(queue) == 0): break
    currNode = queue.pop(0)
    # 현재 노드 주변 탐색
    for i in range(1, len(currNode)):
      start = 0
      end = start + i
      while (end <= len(currNode)):
        newNode = reverseString(currNode, start, end)
        if newNode not in dict:
          dict[newNode] = NumSeq(newNode)
          dict[newNode].setDistance(dict[currNode].getDistance() + 1)
          queue.append(newNode)
        start += 1
        end += 1
  return dict[currNode].getDistance()

N = int(input())
ansList = []
for x in range(N):
  length = input()
  numList = list(map(lambda n: int(n), input().split(' ')))
  sortedList = sorted(numList)
  numSeqStr = ''
  sortedStr = ''
  for i, y in enumerate(numList):
    numSeqStr += str(sortedList.index(y) + 1)
    sortedStr += str(i+1) 
  
  ansList.append(solution(numSeqStr, sortedStr))
for x in ansList:
  print(x)