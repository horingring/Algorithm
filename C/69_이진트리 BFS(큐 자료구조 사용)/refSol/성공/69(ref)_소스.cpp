#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> map[11];
vector<int> visit;
queue<int> q;

void bfs(int x) {
	visit[x] = 1;
	printf("%d ", x);

	for (int j = 0; j < map[x].size(); j++) {
		if (!visit[map[x][j]]) {
			q.push(map[x][j]);
		}
	}

	q.pop();

	while (!q.empty()) {
		bfs(q.front());
	}
}

int main() {
	int m, a, b;
	scanf_s("%d %d", &n, &m);
	visit = vector<int>(n + 1, 0);

	for (int i = 1; i <= m; i++) {
		scanf_s("%d %d", &a, &b);
		map[a].push_back(b);
		map[b].push_back(a);
	}

	q.push(1);
	bfs(1);

	return 0;
}