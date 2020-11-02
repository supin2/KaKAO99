import sys

x, y, z = list(map(lambda n: int(n), sys.stdin.readline().rstrip().split(' ')))
result = 0
A = y if y < z else z
B = y if y > z else z
while A != B:
  A = A - (A // 2)
  B = B - (B // 2)
  result += 1
print(result)