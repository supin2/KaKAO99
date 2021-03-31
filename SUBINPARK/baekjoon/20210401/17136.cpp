#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int MAX = 10;

int ans = INT_MAX, cnt = 0;
int paper[MAX][MAX];
int colored_paper[5] = { 5, 5, 5, 5, 5 };

void input() {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cin >> paper[i][j];
		}
	}
}

void solution(int y, int x) { // DFS
	if (x == MAX) { // 행의 끝 -> 다음 행으로
		solution(y + 1, 0);
		return;
	}
	if (y == MAX) { // 열의 끝 -> 탐색 끝
		ans = min(ans, cnt);
		return;
	}
	if (paper[y][x] == 0) { // 1 나타날때까지 찾기
		solution(y, x + 1);
		return;
	}
	
	for (int size = 5; size > 0; --size) { // 색종이 제일 큰 것부터 붙여보기
		if (colored_paper[size - 1] == 0 || y + size > MAX || x + size > MAX) { // 색종이가 다 떨어지거나 범위 벗어난 경우
			continue;
		}
		
		bool flag = true;
		for (int i = 0; i < size; ++i) { // 선택한 색종이 붙일 수 있는지 체크
			for (int j = 0; j < size; ++j) {
				if (paper[y + i][x + j] == 0) {
					flag = false;
					break;
				}
			}
			if (!flag) break;
		}
		if (!flag) {
			continue;
		}
		
		for (int i = 0; i < size; ++i) { // 색종이 붙이기
			for (int j = 0; j < size; ++j) {
				paper[y + i][x + j] = 0;
			}
		}
		cnt++; // 붙인 색종이 총 개수 ++
		colored_paper[size - 1]--; // 붙인 색종이 개수 줄이기
		
		solution(y, x + size);
		
		for (int i = 0;  i < size; ++i) { // 색종이 다시 떼기
			for (int j = 0; j < size; ++j) {
				paper[y + i][x + j] = 1;
			}
		}
		cnt--; // 다시 되돌리기
		colored_paper[size - 1]++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	input();
	solution(0, 0);
	
	cout << (ans == INT_MAX ? -1 : ans) << endl;
	
	return 0;
}