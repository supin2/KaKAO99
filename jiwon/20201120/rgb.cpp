#include <iostream>
#include <algorithm>
#include <cstring> 

using namespace std;
int N;
int H[1000][3]; // R: 0, G: 1, B: 2
int M[1000][3];
void solution(int i) {
  M[i][0] = min(M[i-1][1], M[i-1][2]) + H[i][0];
  M[i][1] = min(M[i-1][0], M[i-1][2]) + H[i][1];
  M[i][2] = min(M[i-1][1], M[i-1][0]) + H[i][2];
}

int main() {
  // cout << "Hello, World!";
  cin >> N;
  memset(H, 0, sizeof(int) * 3 * N);
  memset(M, 0, sizeof(int) * 3 * 3);

  cin >> H[0][0] >> H[0][1] >> H[0][2];
  M[0][0] = H[0][0];
  M[0][1] = H[0][1];
  M[0][2] = H[0][2];
  for (int i = 1; i < N; i++) {
    cin >> H[i][0] >> H[i][1] >> H[i][2];
    solution(i);
  }
  cout << min({M[N-1][0], M[N-1][1], M[N-1][2]}) << endl;
  return 0;
}