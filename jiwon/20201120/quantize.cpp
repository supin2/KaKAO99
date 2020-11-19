#include <iostream>
#include <algorithm>
#include <cstring> 
#include <cmath>

using namespace std;

const int INF = 987654321;

int C;
int A[101], pSum[101], pSqSum[101];
int R[50];
int cache[101][11];

void precalc(int n) {
  sort(A, A+n);
  pSum[0] = A[0];
  pSqSum[0] = A[0] * A[0];
  for (int i = 1; i < n; i++) {
    pSum[i] = pSum[i-1] + A[i];
    pSqSum[i] = pSqSum[i-1] + A[i] * A[i];
  }
}
int minError(int lo, int hi) {
  int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo-1]);
  int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo-1]);
  int m = int(0.5 + (double)sum/(hi-lo+1));
  int ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1);
  return ret;
}
int quantize(int from, int parts, int n) {
  if (from == n) return 0;
  if (parts == 0) return INF;
  int& ret = cache[from][parts];
  if (ret != -1) return ret;
  ret = INF;
  for (int size = 1; from + size <= n; ++size) {
    ret = min(ret, minError(from, from + size - 1) + quantize(from + size, parts - 1, n));
  }


  return ret;
}

int main() {
  cin >> C;
  int n, s;
  memset(R, 0, sizeof(int) * C);
  for (int i = 0; i < C; i++) {
    cin >> n >> s;
    memset(A, 0, sizeof(int) * n);
    memset(cache, -1, sizeof(int) * 101 * 11);
    memset(pSum, 0, sizeof(int) * n);
    memset(pSqSum, 0, sizeof(int) * n);
    for (int j = 0; j < n; j++) {
      cin >> A[j];
    }
    precalc(n);
    int ret = quantize(0, s, n);
    R[i] = ret;
  }
  for (int i = 0; i < C; i++)
    cout << R[i] << endl;
  return 0;
}