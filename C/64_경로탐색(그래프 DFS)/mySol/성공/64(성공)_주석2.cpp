#include <stdio.h>
#include <vector>
using namespace std;

int n, cnt = 0;
vector < vector <int> > a;	//인접행렬 표
vector <int> visit;  //방문여부
vector <int> order(1, 0);  //방문순서

void DFS(int x) {
	/* 조회 처리 */
	visit[x] = 1;
	order.push_back(x);

	/* 목적지 도달 여부 */
	if (x == n) {  // 도달 시
		cnt++;
		for (int k = 1; k < order.size(); k++) {
			printf("%d ", order[k]);
		}
		printf("\n");
		visit[x] = 0;
		order.pop_back();
		return;
	}
	else {  // 도달하지 않았을 시
		for (int j = 1; j <= n; j++) {
			if (a[x][j] && !visit[j]) {
				DFS(j);
			}
		}
	}

	/* 조회 취소 처리 */
	visit[x] = 0;
	order.pop_back();
}

int main() {
	int m, c, d;
	scanf_s("%d %d", &n, &m);
	/* 새롭게 초기화된 벡터 a와 visit에 대입 */
	a = vector <vector <int> >(n + 1, vector <int>(n + 1, 0));
	visit = vector <int>(n + 1, 0);

	/* 인접행렬 작성 */
	for (int i = 1; i <= m; i++) {
		scanf_s("%d %d", &c, &d);
		a[c][d] = 1;
	}
	
	DFS(1);

	printf("%d", cnt);

	return 0;
}