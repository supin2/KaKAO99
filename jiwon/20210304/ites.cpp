#include <iostream>
#include <algorithm>
#include <cstring> 
#include <math.h>

using namespace std;
int C; // number of test cases
int K;
int N;
long A[50000001];
int a[50000001];
long MAX = 4294967296;

int getSignal(int n) {
  return A[n - 1] % 10000 + 1;
}

int solution(int k, int n) {
  int ret = 0;

  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = i; j <= n; j++) {
      sum += a[j];
      if (sum == k) {
        ret++;
        break;
      }
      if (sum > k) break;
    }
  }

  return ret;
}

int main() {
  cin >> C;
  int outputs[21];

  // init A
  A[0] = 1983;
  for (int i = 1; i <= 50000000; i++) {
    A[i] = (A[i-1] * 214013 + 2531011) % (MAX);
  }
  for (int i = 1; i <= 50000000; i++) {
    a[i] = getSignal(i);
  }

  for (int i = 0; i < C; i++) {
    cin >> K >> N;
    outputs[i] = solution(K, N); 
  }
  for (int i = 0; i < C; i++) {
    cout << outputs[i] << endl; 
  }
  return 0;
}