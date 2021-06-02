#include <stdio.h>

int a[11] = { 0, };

void D(int x, int n) {
	/* 현재 조회하는 수 토글(on/off) */
	if (a[x] == 0) a[x] = 1;
	else a[x] = 0;

	/* 현재 노드가 단말노드(leaf)일 경우, 출력 & return */
	if (x == n) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) printf("%d ", i);
		}
		printf("\n");
		return;
	}

	/* 왼쪽/오른쪽 자식노드 순회 */
	D(x + 1, n);	// 왼쪽 자식노드 : 다음 수가 있는 경우
	D(x + 1, n);	// 오른쪽 자식노드 : 다음 수가 없는 경우
	return;
}


int main() {
	int n;
	scanf("%d", &n);

	D(1, n);	// 1이 있는 경우
	D(1, n);	// 1이 없는 경우

	return 0;
}
