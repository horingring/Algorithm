#include <stdio.h>
#include <vector>
using namespace std;

int main() {
	/* 1. 입력 및 벡터생성 */
	int n, m, i, j, num;
	scanf("%d %d", &n, &m);

	vector < vector <int> > a(n + 1, vector <int>(n + 1, 0));

	/* 2. 인접행렬 정보 입력 */
	for (int k = 0; k < m; k++) {
		scanf("%d %d %d", &i, &j, &num);
		a[i][j] = num;
	}

	/* 3. 출력 */
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}