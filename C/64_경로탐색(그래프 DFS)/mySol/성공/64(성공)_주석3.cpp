#include <stdio.h>
#include <vector>
using namespace std;

int n, cnt = 0;
vector < vector <int> > a;
vector <int> visit;
vector <int> order(1, 0);

void DFS(int x) {
	visit[x] = 1;
	order.push_back(x);

	/* 목적지 도달 여부 */
	if (x == n) {  /* 목적지 도달 시 */
		cnt++; // 1. cnt++
		for (int k = 1; k < order.size(); k++) {  // 2. 경로 출력
			printf("%d ", order[k]);
		}
		printf("\n");
		visit[x] = 0;  // 3. 현재노드 방문취소 처리
		order.pop_back();  // 4. 현재노드 탐색순서 배열에서 제거
		return;  // 5. 현재 DFS 종료
	}
	else {  /* 목적지에 도달하지 않았을 시 */
		for (int j = 1; j <= n; j++) {
			if (a[x][j] && !visit[j]) {  // 1. 검사 --> (1)연결여부 (2)조회여부
				DFS(j);  // 2. 재귀 탐색
			}
		}
	}

	visit[x] = 0;
	order.pop_back();
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