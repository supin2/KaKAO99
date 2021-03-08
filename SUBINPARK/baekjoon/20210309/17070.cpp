#include <iostream>

using namespace std;

const int MAX = 16;
int N;
int house[MAX][MAX];
int result = 0;

int dy[4] = { 0, 1, 1 }; // 가로, 세로, 대각선
int dx[4] = { 1, 0, 1 }; 

void solution(int y, int x, int status) { // status = 가로 : 0, 세로 : 1, 대각선 : 2
    if ((y == N - 1) && (x == N - 1)) { // 도착
        result++;
        return;
    }

    for (int i = 0; i < 3; ++i) {
        if ((status == 0) && (i == 1)) continue; // 가로 -> 세로
        if ((status == 1) && (i == 0)) continue; // 세로 -> 가로

        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (nextY >= N || nextX >= N || house[nextY][nextX] == 1) { // 벗어나거나 벽일 경우
            continue;
        }
        if ((i == 2) && (house[y][x + 1] == 1 || house[y + 1][x] == 1)) { // 대각선일 경우 벽 체크
            continue;
        }

        solution(nextY, nextX, i);
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> house[i][j];
        }
    }
    solution(0, 1, 0);

    cout << result << '\n';

    return 0;
}