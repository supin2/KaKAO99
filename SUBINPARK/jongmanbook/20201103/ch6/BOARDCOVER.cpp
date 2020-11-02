#include <iostream>
#include <vector>

using namespace std;

int tot_case, H, W;
int board[20][20];

const int coverType[4][3][2] = {
    { { 0, 0 }, { 1, 0 }, { 0, 1 } },
    { { 0, 0 }, { 0, 1 }, { 1, 1 } },
    { { 0, 0 }, { 1, 0 }, { 1, 1 } },
    { { 0, 0 }, { 1, 0 }, { 1, -1 } }
};

bool set(int board[][20], int y, int x, int H, int W, int type, int delta) {
    bool ok = true;
    for (int i = 0; i < 3; i++) {
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];

        if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
            ok = false;
        } else if ((board[ny][nx] += delta) > 1) {
            ok = false;
        }
    }
    return ok;
}

int cover(int board[][20], int H, int W) {
    int y = -1, x = -1;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (board[i][j] == 0) {
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1) break;
    }

    if (y == -1) return 1;
    int ret = 0;
    
    for (int type = 0; type < 4; ++type) {
        if (set(board, y, x, H, W, type, 1)) {
            ret += cover(board, H, W);
        }
        set(board, y, x, H, W, type, -1);
    }
    return ret;
}


int main() {
    char chess[20];
    cin >> tot_case;

    if (tot_case < 0 | tot_case > 30) {
        cout << -1;
    }

    for (int i = 0; i < tot_case; i++) {
        cin >> H >> W;

        if (H < 1 || H > 20 || W < 1 || W > 20) {
            cout << -1;
        }

        for (int j = 0; j < H; j++) {
            cin >> chess;
            for (int k = 0; k < W; k++) {
                if (chess[k] == '#') {
                    board[j][k] = 1;
                } else {
                    board[j][k] = 0;
                }
            }
            cout << cover(board, H, W) << endl;
        }
    }
}