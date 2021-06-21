#include <stdio.h>
#include <vector>
using namespace std;

int n, cnt = 0, cost = 0, minCost = 2147000000;
vector < vector <int> > map;
vector <int> visit;

void DFS(int x) {
	visit[x] = 1;

	if (x == n) {
		if (cost < minCost) {
			minCost = cost;
			cnt = 1;
		} 
		else if (cost == minCost) cnt++;

		visit[x] = 0;
		return;
	}

	for (int j = 1; j <= n; j++) {
		if (map[x][j] != 0 && visit[j] != 1) {
			cost += map[x][j];
			DFS(j);
			cost -= map[x][j];
		}
	}

	visit[x] = 0;
}

int main() {
	int m, a, b, c;
	scanf_s("%d %d", &n, &m);
	map = vector < vector <int> >(n + 1, vector<int>(n + 1, 0));
	visit = vector<int>(n + 1, 0);
	for (int i = 0; i < m; i++) {
		scanf_s("%d %d %d", &a, &b, &c);
		map[a][b] = c;
	}

	DFS(1);

	printf("%d %d", minCost, cnt);

	return 0;
}