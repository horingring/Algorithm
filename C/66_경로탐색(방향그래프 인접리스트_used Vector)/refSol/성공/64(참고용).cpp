#include <stdio.h>
#include <vector>
using namespace std;

int n, cnt = 0;
vector < vector <int> > map;
vector <int> visit;


void DFS(int x) {
	visit[x] = 1;
	
	if (x == n) {
		cnt++;
		visit[x] = 0;
		return;
	}

	for (int k = 1; k <= n; k++) {
		if (map[x][k] && !visit[k]) DFS(k);
	}

	visit[x] = 0;
}

int main() {
	int m;
	int a, b;
	scanf_s("%d %d", &n, &m);
	map = vector< vector <int> >(n + 1, vector <int>(n + 1, 0));
	visit = vector<int>(n + 1, 0);
	for (int i = 0; i < m; i++) {
		scanf_s("%d %d", &a, &b);
		map[a][b] = 1;
	}

	DFS(1);

	printf("%d", cnt);

	return 0;
}