#include <stdio.h>
#include <stdlib.h>		//프로그램 즉시 종료(exit) 함수를 위한 include

int a[11][2] = { 0, };
int n;

void DFS(int x) {
	if (a[x][1] == 0) a[x][1] = 1;
	else a[x][1] = 0;

	if (x == n) {
		int sumA = 0;
		int sumB = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i][1] == 1) sumA += a[i][0];
			else sumB += a[i][0];
		}
		if (sumA == sumB) {
			printf("YES");
			exit(0);  //프로그램 즉시 종료 ( * <stdlib.h>에서 가져옴 )
		}

		return;
	}

	DFS(x + 1);
	DFS(x + 1);

	return;
}

int main() {
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &a[i][0]);
	}

	DFS(1);
	DFS(1);

	printf("NO");

	return 0;
}