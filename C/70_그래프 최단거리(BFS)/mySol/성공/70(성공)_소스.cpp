#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> map[21];
vector<int> qIn;
vector<int> minCourse;
queue<int> q;

void bfs(int x, int depth) {
	minCourse[x] = depth-1;

	int flag = 0;
	
	for (int k = 0; k < map[x].size(); k++) {
		if (!qIn[map[x][k]]) {
			q.push(map[x][k]);
			qIn[map[x][k]] = 1;
			flag++;
		}
	}
	q.pop();
	if (flag == 0) return;

	depth++;
	while (!q.empty()) {
		bfs(q.front(), depth);
	}
}

int main() {
	int m, a, b;
	scanf_s("%d %d", &n, &m);
	qIn = vector<int>(n + 1, 0);
	minCourse = vector<int>(n + 1, 0);

	for (int i = 0; i < m; i++) {
		scanf_s("%d %d", &a, &b);
		map[a].push_back(b);
	}

	q.push(1);
	qIn[1] = 1;

	bfs(1, 1);

	for (int i = 2; i <= n; i++) {
		printf("%d : %d\n", i, minCourse[i]);
	}

	return 0;
}
