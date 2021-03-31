#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

const int MAX = 11;

int N, ans = INT_MAX;
int population_info[MAX]; // 지역구별 인구정보
bool visit[MAX];
vector<int> link_info[MAX]; // 지역구 간 연결정보
vector<int> district;

void input() {
	cin >> N;
	
	for (int i = 1; i <= N; ++i) {
		cin >> population_info[i];
	}
	
	int temp, neighbor;
	for (int i = 1; i <= N; ++i) {
		cin >> temp;
		for (int j = 0; j < temp; ++j) {
			cin >> neighbor;
			link_info[i].push_back(neighbor);
		}
	}
}

bool isConnected(vector<int> V) { // BFS
	memset(visit, false, sizeof(visit));
	queue<int> q;
	q.push(V[0]);
	visit[V[0]] = true;
	
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		
		for (int i = 0; i < link_info[now].size(); ++i) {
			int next = link_info[now][i];
			vector<int>::iterator it = find(V.begin(), V.end(), next); // 같은 선거구에 포함되어있는지 확인
			
			if (it == V.end()) { // 같은 선거구에 포함되어있지 않음
				continue;
			}
			if (visit[next]) {
				continue;
			}
			visit[next] = true;
			q.push(next);
		}
	}
	for (int i = 0; i < V.size(); ++i) {
		if (!visit[V[i]]) { // 연결되지 않은 곳이 존재
			return false;
		}
	}
	return true;
}

void solution() {
	vector<int> red, blue;
	
	for(int i = 0; i < district.size(); ++i) { // 지역구 빨간, 파랑 나누기
		district[i] == 0 ? red.push_back(i + 1) : blue.push_back(i + 1);
	}
	
	if (!isConnected(red) || !isConnected(blue)) { // 
		return;
	}
	
	int pop = 0;
	
	for (int i = 0; i < red.size(); ++i) {
		pop += population_info[red[i]];
	}
	for (int i = 0; i < blue.size(); ++i) {
		pop -= population_info[blue[i]];
	}
	
	ans = min(ans, abs(pop));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	input();
	
	int i, j;
	
	for (i = 1; i < N; ++i) { // 선거구를 뽑을 조합 구현
		for (j = 0; j < i; ++j) {
			district.push_back(0);
		}
		for (j = 0; j < N - i; ++j) {
			district.push_back(1);
		}
		
		do {
			solution();
		} while(next_permutation(district.begin(), district.end()));
		
		district.clear();
	}
	
	cout << (ans == INT_MAX ? -1 : ans) << '\n';
	return 0;
}