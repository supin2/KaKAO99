import sys
sys.setrecursionlimit(10**7)
C = int(sys.stdin.readline().rstrip())
PLIST = []
for x in range(C):
  inputD = sys.stdin.readline().rstrip().split(' ')
  H = int(inputD[0])
  W = int(inputD[1])
  map = []
  for y in range(H):
    map.append(list(sys.stdin.readline().rstrip()))
  for i in range(H):
    for j in range(W):
      map[i][j] = 1 if map[i][j] == '#' else 0
  PLIST.append([H, W, map])

coverType = [
  [[0,0], [1,0], [0,1]],
  [[0,0], [0,1], [1,1]],
  [[0,0], [1,0], [1,1]],
  [[0,0], [1,0], [1,-1]],
]

def set(map, y, x, type, delta):
  ok = True
  for i in range(3):
    ny = y + coverType[type][i][0]
    nx = x + coverType[type][i][1]
    if ny < 0 or ny >= len(map) or nx < 0 or nx >= len(map[0]):
      ok = False
    elif (map[ny][nx] + delta) > 1:
      ok = False
  return ok

def cover(map):
  y, x = -1, -1
  for i in range(len(map)):
    for j in range(len(map[i])):
      if (map[i][j] == 0):
        y = i
        x = j
        break
    if y != -1:
      break
  
  if (y == -1): return 1

  ret = 0
  for type in range(4):
    if (set(map, y, x, type, 1)):
      ret += cover(map)
    set(map, y, x, type, -1)
  return ret

for p in PLIST:
  print(cover(p[2]))
