#include <iostream>
using namespace std;
int N; // number of test cases
const int MAX = 17;
int MAP[MAX][MAX];
int ans = 0;
// type : 0, 1, 2
void solution(int x, int y, int type) {
  // cout << x << y << type << endl;
  if (x == N && y == N) { 
    ans++;
    return;
  }
  if (type == 0) {
    if (x + 1 <= N && y <= N && MAP[x+1][y] == 0) {
      solution(x+1, y, 0);
    }
    if (x + 1 <= N && y + 1 <= N && (MAP[x+1][y] + MAP[x][y+1] + MAP[x+1][y+1]) == 0) {
      solution(x+1, y+1, 2);
    }
  }
  if (type == 1) {
    if (x<= N && y + 1 <= N && MAP[x][y+1] == 0) {
      solution(x, y+1, 1);
    }
    if (x + 1 <= N && y + 1 <= N && (MAP[x+1][y] + MAP[x][y+1] + MAP[x+1][y+1]) == 0) {
      solution(x+1, y+1, 2);
    }
  }
  if (type == 2) {
    if (x + 1 <= N && y <= N && MAP[x+1][y] == 0) {
      solution(x+1, y, 0);
    }
    if (x<= N && y + 1 <= N && MAP[x][y+1] == 0) {
      solution(x, y+1, 1);
    }
    if (x + 1 <= N && y + 1 <= N && (MAP[x+1][y] + MAP[x][y+1] + MAP[x+1][y+1]) == 0) {
      solution(x+1, y+1, 2);
    }
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> MAP[j][i];
    }
  }
  solution(2, 1, 0);
  cout << ans;
  return 0;
}