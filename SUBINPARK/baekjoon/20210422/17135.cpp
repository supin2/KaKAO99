// 백준 17135번 : 캐슬 디펜스
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 15 + 1;
int N, M, D, ret = 0;
int matrix[MAX][MAX];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> D;


    vector<pair<int, int>> enemy;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> matrix[i][j];
            
            if (matrix[i][j] == 1) {
                enemy.push_back(make_pair(i, j)); // 적 위치 전부 저장
            }
        }
    }

    vector<int> hunter;
    // 궁수 위치 조합 구현
    for (int i = 0; i < M - 3; ++i) {
        hunter.push_back(0);
    }
    for (int i = 0; i < 3; ++i) { 
        hunter.push_back(1);
    }

    do {
        vector<pair<int, int>> copy_enemy = enemy;
        vector<int> v;
        int cnt = 0;

        for (int i = 0; i < hunter.size(); ++i) {
            if (hunter[i] == 1) {
                v.push_back(i); // 궁수들 현재 위치 저장
            }
        }

        while(!copy_enemy.empty()) { // 적이 다 죽을 때까지
            int y = N;
            vector<int> attack;

            for (int i = 0; i < v.size(); ++i) { // 각 궁수들의 공격대상 설정
                int idx = 0; // 공격대상 저장용
                int x = v[i];
                int target_Y = copy_enemy[0].first;
                int target_X = copy_enemy[0].second;
                int dist = abs(y - target_Y) + abs(x - target_X);
                
                for (int j = 1; j < copy_enemy.size(); ++j) { // 조건에 맞는 공격대상 찾기
                    int temp_Y = copy_enemy[j].first;
                    int temp_X = copy_enemy[j].second;
                    int temp_dist = abs(y - temp_Y) + abs(x - temp_X);

                    if (dist > temp_dist) { // 더 가까운 적이 있을 경우
                        target_X = temp_X;
                        dist = temp_dist;
                        idx = j;
                    } else if (dist == temp_dist && target_X > temp_X) { // 거리는 같고, 적이 더 왼쪽에 있을 경우
                        target_X = temp_X;
                        idx = j;
                    }
                }
                
                if (dist <= D) { // D 거리 내에 있는 적만 공격가능
                    attack.push_back(idx);
                }
            }

            attack.erase(unique(attack.begin(), attack.end()), attack.end()); // 중복 공격 대상 제거
            sort(attack.begin(), attack.end());

            int kill = 0;
            for (int i = 0; i < attack.size(); ++i) { // 적 제거
                copy_enemy.erase(copy_enemy.begin() + (attack[i] - kill++));
                cnt++;
            }

            if (copy_enemy.empty()) {
                break;
            }

            vector<pair<int, int>> temp;
            for (int i = 0; i < copy_enemy.size(); ++i) { // 살아있는 적들 한 칸씩 이동
                if (copy_enemy[i].first < N - 1) {
                    temp.push_back(make_pair(copy_enemy[i].first + 1, copy_enemy[i].second));
                }
            }
            copy_enemy = temp;
        }
        ret = max(ret, cnt);
        
    } while(next_permutation(hunter.begin(), hunter.end()));

    cout << ret << '\n';
    return 0;
}