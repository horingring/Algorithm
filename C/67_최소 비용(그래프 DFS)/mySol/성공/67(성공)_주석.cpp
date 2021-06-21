#include <stdio.h>
#include <vector>
using namespace std;

int n, cnt = 0, cost = 0, minCost = 2147000000;
vector < vector <int> > map;
vector <int> visit;

void DFS(int x) {
	/* 방문처리 */
	visit[x] = 1;

	/* 도착점 도달 시 */
	if (x == n) {
		/* 최소 비용과 비교 */
		if (cost < minCost) {
			minCost = cost;
			cnt = 1;
		} 
		else if (cost == minCost) cnt++;

		visit[x] = 0;
		return;
	}

	/* 다음 노드 방문 & 비용 적용 */
	for (int j = 1; j <= n; j++) {
		if (map[x][j] != 0 && visit[j] != 1) {
			cost += map[x][j];	// 다음 노드 방문 직전, 비용 계산(비용 추가)
			DFS(j);  // 노드 방문
			cost -= map[x][j];  // 노드에서 빠져나온 직후, 비용 계산(다시 차감)
		}
	}

	/* 방문 취소 처리 */
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