#include <iostream>
#include <algorithm>
#include <cstring> 

using namespace std;
int N;
int K;
int IN[100][2];
int V[100][100];
int W[100][100];
int MAX = 0;
void solution(int len, int weight, int i) {
  for (int j = 0; j < len; j++) {
    if (i == j) {
      W[i][j] = W[i-1][j];
      V[i][j] = V[i-1][j];
      // cout << V[i][j] << ' ';
      continue;
    }
    W[i][j] = IN[i][0] + W[i-1][j];
    if (W[i][j] <= weight) {
      V[i][j] = V[i-1][j] + IN[i][1];
      MAX = (MAX < V[i][j]) ? V[i][j] : MAX;
    }
    else V[i][j] = V[i-1][j];
    // cout << V[i][j] << ' ';
  }
  // cout << endl;
}


int main() {
  // cout << "Hello, World!";
  cin >> N >> K;
  memset(IN, 0, sizeof(int) * 2 * N);
  memset(V, 0, sizeof(int) * N * N);
  memset(W, 0, sizeof(int) * N * N);

  for (int i = 0; i < N; i++) {
    cin >> IN[i][0] >> IN[i][1];
  }
  for (int i =0; i < N; i++) {
    W[0][i] = IN[i][0];
    V[0][i] = IN[i][1];
    if (i != 0) {
      if (W[0][i] + W[0][0] <= K) {
        W[0][i] += W[0][0];
        V[0][i] += V[0][i];
      } 
    }
    if (W[0][i] <= K) {
      MAX = (MAX < V[0][i]) ? V[0][i] : MAX;
    } else {
      V[0][i] = -1;
    }
    // cout << "MAX" << MAX;
    // cout << V[0][i] << ' ';
  }
  // cout << endl;
  for (int i = 1; i < N; i++) {
    solution(N, K, i);
    // cout << "Value" <<endl;
    // for (int j = 0; j < N; j++) {
    //   for (int k = 0; k < N; k++) {
    //     cout << V[j][k] << ' ';
    //   }
    //   cout << endl;
    // }
    // cout << "Weight" <<endl;
    // for (int j = 0; j < N; j++) {
    //   for (int k = 0; k < N; k++) {
    //     cout << W[j][k] << ' ';
    //   }
    //   cout << endl;
    // }
  }
  cout << MAX << endl;
  return 0;
}