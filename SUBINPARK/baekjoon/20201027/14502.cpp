#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 8
using namespace std;

int n, m, space, result;
int map[MAX][MAX];
int cmap[MAX][MAX];
bool flag[MAX * MAX];
bool visit[MAX][MAX];
vector<pair<int, int>> virus, zero;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };


void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) zero.push_back(make_pair(i, j)); //0이 있는 좌표의 위치를 zero 벡터에 삽입
			if (map[i][j] == 2) virus.push_back(make_pair(i, j)); //바이러스 (2) 좌표의 위치를 virus 벡터에 삽입
		}
	}

	space = zero.size(); //0의 개수
}

void bfs(int x, int y) {
	//바이러스가 있는 좌표의 위치를 queue에 삽입
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = true;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (!visit[nx][ny] && cmap[nx][ny] == 0) { //방문하지 않았고 벽이 아닌 경우
				cmap[nx][ny] = 2; //바이러스를 퍼뜨림
				visit[nx][ny] = true;
				q.push(make_pair(nx, ny)); //바이러스를 퍼뜨린 좌표를 q에 재삽입
			}
			
		}
	}
}

//바이러스를 퍼뜨림.
void spread_virus() {
	int cnt = 0;

	//먼저 cmap에 원본 map을 복사해줌.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cmap[i][j] = map[i][j];
		}
	}

	//visit을 전부 false로 초기화
	memset(visit, false, sizeof(visit));

	//앞서 0이 있는 자리에 벽이 세워진 경우 cmap에도 반영해줌!
	for (int i = 0; i < space; i++) {
		if (cnt == 3) break; //벽이 세개가 채워지면 루프 중단
		if (flag[i] == true) {
			int x = zero[i].first;
			int y = zero[i].second;
			cmap[x][y] = 1;
			cnt++;
		}
	}

	//바이러스가 있는 곳 주변으로 bfs 실행
	for (int i = 0; i < virus.size(); i++) {
		int x = virus[i].first;
		int y = virus[i].second;
		bfs(x, y);
	}

	//바이러스를 모두 퍼뜨린 이후
	int safe = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cmap[i][j] == 0) safe++; //안전한 곳의 위치를 카운트
		}
	}

	//안전한 곳의 개수 중 더 큰 것을 result에 저장!
	result = (result > safe ? result : safe);
}

//0이 있는 모든 곳 중 3군데에 벽을 세움.
void make_wall(int idx, int cnt) {
	if (cnt == 3) { //3군데가 세워지면
		spread_virus(); //바이러스를 퍼뜨림
		return;
	}

	//0이 있는 자리에 벽을 세웠을 경우 flag = true로 바꾸어줌.
	for (int i = idx; i < space; i++) {
		if (flag[i] == true) continue;
		flag[i] = true;
		make_wall(i, cnt + 1);
		flag[i] = false;
	}
}

int main() {

	input(); 
    
	make_wall(0, 0);

	cout << result << "\n";

	return 0;
}