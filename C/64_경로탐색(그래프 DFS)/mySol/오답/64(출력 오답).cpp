#include <stdio.h>
#include <vector>
using namespace std;

int n, cnt = 0;
vector < vector <int> > a;
vector <int> visit;

void DFS(int x) {
	visit[x] = 1;

	if (x == n) {
		cnt++;
		// 잘못된 부분 (여기부터)
		for (int k = 1; k <= n; k++) {
			if (visit[k] == 1) printf("%d ", k);
		}
		// 잘못된 부분 (여기까지)
		// * 오답 이유 : 방문한 노드를 출력했을 뿐, 그것이 방문했던 순서를 나타내지는 않기 때문.
		printf("\n");
		visit[x] = 0;
		return;
	}
	else {
		for (int j = 1; j <= n; j++) {
			if (a[x][j] && !visit[j]) {
				DFS(j);
			}
		}
	}

	visit[x] = 0;
}

int main() {
	int m, c, d;
	scanf_s("%d %d", &n, &m);
	a = vector <vector <int> >(n + 1, vector <int>(n + 1, 0));
	visit = vector <int>(n + 1, 0);

	for (int i = 1; i <= m; i++) {
		scanf_s("%d %d", &c, &d);
		a[c][d] = 1;
	}
	
	DFS(1);

	printf("%d", cnt);

	return 0;
}