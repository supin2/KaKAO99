import sys
import copy
N, M = list(map(lambda n: int(n), sys.stdin.readline().split(' ')))
MAP = []
POSITION_OF_ZERO = []
POSITION_OF_VIRUS = []
MAP_SIZE = N * M
NUM_OF_WALL = 0
NUM_OF_VIRUS = 0
for x in range(N):
  MAP.append(list(map(lambda n: int(n), sys.stdin.readline().split(' '))))
  for y in range(M):
    if MAP[x][y] == 0: POSITION_OF_ZERO.append([x, y])
    elif MAP[x][y] == 1: NUM_OF_WALL += 1
    else:
      NUM_OF_VIRUS += 1
      POSITION_OF_VIRUS.append([x, y])
NUM_OF_WALL += 3 # 3개의 벽 추가


def DFS(pos, map):
  xPos, yPos = pos
  # print('[', xPos, ']', '[', yPos, ']', end='\n')
  ret = 1 if map[xPos][yPos] == 3 else 0

  up = map[xPos - 1][yPos] if xPos > 0 else -1
  down = map[xPos + 1][yPos] if xPos < N-1 else -1
  left = map[xPos][yPos - 1] if yPos > 0 else -1
  right = map[xPos][yPos +1] if yPos < M-1 else -1
  
  if up == 0:
    map[xPos - 1][yPos] = 3
    ret += DFS([xPos - 1, yPos], map)
  if down == 0:
    map[xPos + 1][yPos] = 3
    ret += DFS([xPos + 1, yPos], map)
  if left == 0:
    map[xPos][yPos - 1] = 3
    ret += DFS([xPos, yPos - 1], map)
  if right == 0:
    map[xPos][yPos + 1] = 3
    ret += DFS([xPos, yPos + 1], map)
  return ret


def solution():
  # print(NUM_OF_VIRUS, NUM_OF_WALL, MAP_SIZE)
  l = len(POSITION_OF_ZERO)
  ans = -1
  for i in range(l):
    for j in range(i+1, l):
      for k in range(j+1, l):
        # temp = 0
        zeros = 0
        map = copy.deepcopy(MAP)
        map[POSITION_OF_ZERO[i][0]][POSITION_OF_ZERO[i][1]] = 1
        map[POSITION_OF_ZERO[j][0]][POSITION_OF_ZERO[j][1]] = 1
        map[POSITION_OF_ZERO[k][0]][POSITION_OF_ZERO[k][1]] = 1
        for virus in POSITION_OF_VIRUS:
          DFS(virus, map)
        for line in map:
          zeros += line.count(0)
        ans = zeros if zeros > ans else ans
        # for virus in POSITION_OF_VIRUS:
        #   temp += DFS(virus, map)
        # temp = MAP_SIZE - (temp + NUM_OF_VIRUS + NUM_OF_WALL)
        # ans = temp if ans < temp else ans
  return ans

print(solution())




