#include <iostream>
#include <cstring>

using namespace std;

const int num_of_players = 10;
const int max_inning = 51;

int N, ans;
int yagu[max_inning][num_of_players];
int line_up[num_of_players];
bool select_chk[num_of_players];


int bigger (int a, int b) {
    return a > b ? a : b;
}


void play_ball() {
    bool base[4]; // 0 : 홈, 1 : 1루, 2 : 2루, 3 : 3루
    int score = 0;
    int start_player = 1;

    for (int i = 1; i <= N; ++i) { // N이닝 동안 진행
        int out_cnt = 0;
        bool inning_chk = false;
        memset(base, false, sizeof(base));

        while (true) {
            for (int j = start_player; j < num_of_players; ++j) {
                int hitter = yagu[i][line_up[j]];

                if (hitter == 0) { // 아웃
                    out_cnt++;
                } else if (hitter == 1) { // 안타
                    for (int k = 3; k > 0; k--) {
                        if (base[k]) {
                            if (k == 3) { // 3루 주자 진루 후 득점
                                base[k] = false;
                                score++;
                            } else { // 2루, 1루 주자 진루
                                base[k + 1] = true;
                                base[k] = false;
                            }
                        } 
                    }
                    base[1] = true;
                } else if (hitter == 2) { // 2루타
                    for (int k = 3; k > 0; k--) {
                        if (base[k]) {
                            if (k == 3) { // 3루 주자 진루 후 득점
                                base[k] = false;
                                score++;
                            } else if (k == 2) { // 2루 주자 진루 후 득점
                                base[k] = false;
                                score++;
                            } else { // 1루 주자 진루
                                base[k + 2] = true;
                                base[k] = false;
                            }
                        }
                    }
                    base[2] = true;
                } else if (hitter == 3) { // 3루타
                    for (int k = 3; k > 0; k--) {
                        if (base[k]) {
                            base[k] = false;
                            score++;
                        }
                    }
                    base[3] = true;
                } else { // 홈런
                    for (int k = 3; k > 0; k--) {
                        if (base[k]) {
                            base[k] = false;
                            score++;
                        }
                    }
                    score++;
                }

                if (out_cnt == 3) { // 3 아웃
                    start_player = j + 1;
                    if (start_player == num_of_players) {
                        start_player = 1;
                    }
                    inning_chk = true;
                    break;
                }
            }
            if (inning_chk) break;
            start_player = 1;

        }
    }
    ans = bigger(ans, score);
}


void DFS(int num) { // 9명 line up 생성(순열)
    if (num == num_of_players) { // 9명 전부 선택됨
        play_ball(); // 게임시작
        return;
    }

    for (int i = 1; i < num_of_players; ++i) {
        if (select_chk[i]) {
            continue;
        }

        select_chk[i] = true;
        line_up[i] = num;
        DFS(num + 1);
        select_chk[i] = false;
    }
}

void solution() {
    select_chk[4] = true; // 4번타자 선택
    line_up[4] = 1; // 4번타자 = 1번
    DFS(2);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j < num_of_players; ++j) {
            cin >> yagu[i][j];
        }
    }
    solution();

    return 0;
}