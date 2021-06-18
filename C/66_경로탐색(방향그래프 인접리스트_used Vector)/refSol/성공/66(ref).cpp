#include <stdio.h>
#include <vector>
using namespace std;

int n, cnt = 0;
vector <int> map[21];
vector <int> visit;

void DFS(int x) {
	visit[x] = 1;

	if (x == n) {
		cnt++;
		visit[x] = 0;
		return;
	}

	for (int k = 0; k < map[x].size(); k++) {
		if (visit[map[x][k]] == 0) DFS(map[x][k]);
	}

	visit[x] = 0;
}

int main() {
	int m, a, b;
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf_s("%d %d", &a, &b);
		map[a].push_back(b);
	}
	visit = vector<int>(n + 1);

	DFS(1);

	printf("%d", cnt);

	return 0;
}