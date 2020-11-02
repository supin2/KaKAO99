#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int vertex, edge, start;
int matrix[1001][1001];
bool visited[1001];
queue<int> Q;


void DFS(int s) {
	cout << s << " ";

	for (int i = 1; i <= vertex; i++) {
		if (matrix[s][i] && !visited[i]) {
			visited[i] = true;
			DFS(i);
		}
	}
}

void BFS(int s) {
	Q.push(s);
	visited[s] = true;

	while (!Q.empty()) {
		s = Q.front();
		Q.pop();

		cout << s << " ";

		for (int i = 1; i <= vertex; i++) {
			if (matrix[s][i] && !visited[i]) {
				visited[i] = true;
				Q.push(i);
			}
		}
	}
}

int main() {
	cin >> vertex >> edge >> start;

	for (int i = 0; i < edge; i++) {
		int from, to;
		cin >> from >> to;
		matrix[from][to] = 1;
		matrix[to][from] = 1;
	}

	// visited[start] = true;
	// DFS(start);
	// cout << endl;

	memset(visited, false, sizeof(visited));
	BFS(start);
	cout << endl;

	return 0;
}