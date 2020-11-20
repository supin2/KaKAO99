#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, K, W, V;
    int backpack[101][2] = { 0, };
    int cache[101][100001] = { 0, };

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> backpack[i][0] >> backpack[i][1];
    }

    for (int i = 0; )

}