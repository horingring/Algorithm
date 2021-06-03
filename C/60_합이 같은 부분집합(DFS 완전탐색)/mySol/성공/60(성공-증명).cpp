#include <stdio.h>
#include <stdlib.h>

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
			// 60(성공).cpp와 다른 부분 (* groupA 출력)
			printf("groupA : ");
			for(int j=1; j<=n; j++){
				if(a[j][1] == 1){
					printf("%d ", a[j][0]);
				}				
			}
			printf("\n");
			
			// 60(성공).cpp와 다른 부분 (* groupB 출력)
			printf("groupB : ");
			for(int j=1; j<=n; j++){
				if(a[j][1] == 0){
					printf("%d ", a[j][0]);
				}				
			}
			printf("\n");

			// 60(성공).cpp와 다른 부분 (* sum 출력)
			printf("sum : %d\n", sumA);

			printf("YES");
			exit(0);
		}

		return;
	}

	DFS(x + 1);
	DFS(x + 1);

	return;
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i][0]);
	}

	DFS(1);
	DFS(1);

	printf("NO");

	return 0;
}
