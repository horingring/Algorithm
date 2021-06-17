#include <stdio.h>
#include <vector>
using namespace std;

int n, cnt = 0;
vector < vector <int> > a;

void DFS(int row, int col) {
	/* 노드가 벽(1)이거나 이미 조회했던 노드(2) 인 경우 return */
	if (a[row][col] == 2 || a[row][col] == 1) return;

	/* 노드가 도착점인 경우 */
	if (a[row][col] == 3) {
		cnt++;
		return;
	}

	/* 위의 경우들이 아니라면 아직 안가본(0) 노드임 */
	// 1. 조회 처리
	a[row][col] = 2;

	// 2. 하-우-상-좌 순서로 미로탐색 (*순서는 그냥 내가 정함)
	if (row + 1 <= n) DFS(row + 1, col);  //하
	if (col + 1 <= n) DFS(row, col + 1);  //우
	if (row - 1 >= 1) DFS(row - 1, col);  //상
	if (col - 1 >= 1) DFS(row, col - 1);  //좌

	// 3. 조회 취소 처리
	a[row][col] = 0;
}

int main() {
	/* 입력 & 벡터 초기화 */
	scanf_s("%d", &n);
	a = vector < vector <int> >(n + 1, vector <int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}

	a[n][n] = 3;  // 도착점 = 3

	DFS(1, 1);  // 미로탐색 시작

	printf("%d", cnt);  // 출력

	return 0;
}