#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;

int n, cost = 0, minCost = 2147000000;
vector < pair<int, int> > map[31];
vector <int> visit;

void DFS(int x) {
	if (x == n) {
		if (cost < minCost) {
			minCost = cost;
			return;
		 }
	}

	for (int j = 0; j < map[x].size(); j++) {    // map[x]에 링크되어 있는 수만큼 반복
		int currentNode = map[x][j].first;
		int currentCost = map[x][j].second;
		if (!visit[currentNode]) {  // 방문여부 확인    // currentNode 자체가 현재노드 x와 연결되어 있다는 뜻이므로, 인접여부는 확인할 필요 없음
			cost += currentCost;
			visit[currentNode] = 1;
			DFS(currentNode);
			visit[currentNode] = 0;
			cost -= currentCost;
		}
	}
}

int main() {
	int m, a, b, c;
	scanf_s("%d %d", &n, &m);
	visit = vector<int>(n + 1, 0);
	for (int i = 0; i < m; i++) {
		scanf_s("%d %d %d", &a, &b, &c);
		map[a].push_back(make_pair(b, c));
	}

	DFS(1);

	printf("%d", minCost);

	return 0;
}