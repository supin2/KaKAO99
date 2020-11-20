#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int N;
    int R, G, B;
    int ans = 0;
    int arr[1000][3] = { 0, };
    int cache[1000][3] = { 0, };

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    cache[0][0] = arr[0][0];
    cache[0][1] = arr[0][1];
    cache[0][2] = arr[0][2];

    for (int i = 1; i < N; i++) {
        cache[i][0] = min(cache[i - 1][1], cache[i - 1][2]) + arr[i][0];
        cache[i][1] = min(cache[i - 1][0], cache[i - 1][2]) + arr[i][1];
        cache[i][2] = min(cache[i - 1][0], cache[i - 1][1]) + arr[i][2];
    }

    cout << min({cache[N - 1][0], cache[N - 1][1], cache[N - 1][2]}) << endl;
    return 0;
}