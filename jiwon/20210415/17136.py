# INPUT = ['0000000000',
# '1111100000',
# '1111101111',
# '1111101111',
# '1111101111',
# '1111101111',
# '0000000000',
# '0111011000',
# '0111011000',
# '0111000001']
# INPUT = [
# '0000000000',
# '0110000000',
# '0010000000',
# '0000110000',
# '0000010000',
# '0000000000',
# '0010000000',
# '0000000000',
# '0000000000',
# '0000000000']
INPUT = []
for x in range(10):
  inp = input()
  INPUT.append(inp.replace(' ', ''))
FLAGS = [0, 0, 0, 0, 0, 0]
TEMP = list(INPUT)
COUNT = 0
def attach(size):
  if FLAGS[size] >= 5:
    return
  global COUNT
  s = '1' * size
  cnt = 0
  for i in range(10):
    idx = TEMP[i].find(s)
    if idx >= 0:
      cnt += 1
    else: 
      cnt = 0
    if cnt == size:
      FLAGS[size] += 1
      for j in range(size):
        TEMP[i - j] = TEMP[i - j].replace(s, '0' * size, 1)
      COUNT += 1
      cnt = 0
  # print(size, FLAGS[size])
  # for line in TEMP:
  #   print(line)
  # print()

def check():
  flag = True
  for line in TEMP:
    if line.find('1') > 0:
      flag = False
      break
  return flag

def solution():
  for x in range(5): attach(5)
  for x in range(5): attach(4)
  for x in range(5): attach(3)
  for x in range(5): attach(2)
  for x in range(5): attach(1)
  ret = COUNT if check() else -1
  return ret

print(solution())

  