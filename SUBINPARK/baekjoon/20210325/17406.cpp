#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <math.h>

using namespace std;

#define MAX 51

int N, M, K, ans = 9999999;
int arr[MAX][MAX];
int copy_arr[MAX][MAX];


typedef struct {
    int R, C, S;
} Rotate_info;

vector<Rotate_info> V; // 모든 회전 방법
vector<int> rotate_order; // 회전 순서

int dy[4] = { 1, 0, -1,  0}; // 남, 동, 북, 서
int dx[4] = { 0, 1,  0, -1};

void rotate_arr(Rotate_info ri) { // 배열 돌리기
    int Start_Y = ri.R - ri.S;
    int Start_X = ri.C - ri.S;
    int End_Y = ri.R + ri.S;
    int End_X = ri.C + ri.S;

    int tot_rotate = (End_X - Start_X)/2; // 돌려야하는 배열 수(네모 수)

    for (int i = 0; i < tot_rotate; ++i) {
        int tempY = Start_Y;
        int tempX = Start_X;
        int first_value = copy_arr[tempY][tempX];
        int dir = 0;

        while (true) {
            int nextY = tempY + dy[dir]; // 반시계 방향으로 돌기 (남, 동, 북, 서)
            int nextX = tempX + dx[dir];

            if (nextY == Start_Y && nextX == Start_X) { // 시작지점 도착
                copy_arr[tempY][tempX] = first_value;
                break;
            }

            if (Start_Y <= nextY && nextY <= End_Y - i && Start_X <= nextX && nextX <= End_X - i) { // 범위 체크
                copy_arr[tempY][tempX] = copy_arr[nextY][nextX];
                tempY = nextY;
                tempX = nextX;
            } else {
                dir++;
            }
        }
        Start_Y++; // 다음 배열 첫 시작점으로 이동
        Start_X++;
    }
}

void solution() {
    int i, j;
    for (i = 0; i < V.size(); ++i) {
        rotate_arr(V[rotate_order[i]]);
    }
    
    for (i = 1; i <= N; ++i) { // 최솟값 계산
        int row_sum = 0;
        for (j = 1; j <= M; ++j) {
            row_sum += copy_arr[i][j];
        }
        ans = min(row_sum, ans);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int i, j;
    
    cin >> N >> M >> K;

    for (i = 1; i <= N; ++i) {
        for (j = 1; j <= M; ++j) {
            cin >> arr[i][j];
        }
    }

    for (i = 0; i < K; ++i) {
        Rotate_info temp;
        cin >> temp.R >> temp.C >> temp.S;

        rotate_order.push_back(i);
        V.push_back(temp);
    }

    do { // 회전순서 만들기
        memset(copy_arr, 0, sizeof(copy_arr));

        for (i = 1; i <= N; ++i) { // 회전 수행할 배열 복사
            for (j = 1; j <= M; ++j) {
                copy_arr[i][j] = arr[i][j];
            }
        }
        solution();
    } while (next_permutation(rotate_order.begin(), rotate_order.end()));

    cout << ans << '\n';
    return 0;
}