#include <stdio.h>
#include <vector>
using namespace std;

int n, cnt = 0;
vector < vector <int> > a;

void DFS(int row, int col) {
	if (a[row][col] == 2 || a[row][col] == 1) return;
	if (a[row][col] == 3) {
		cnt++;
		return;
	}

	a[row][col] = 2;

	if (row + 1 <= n) DFS(row + 1, col);
	if (col + 1 <= n) DFS(row, col + 1);
	if (row - 1 >= 1) DFS(row - 1, col);
	if (col - 1 >= 1) DFS(row, col - 1);

	a[row][col] = 0;
}

int main() {
	scanf_s("%d", &n);
	a = vector < vector <int> >(n + 1, vector <int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}

	a[n][n] = 3;

	DFS(1, 1);

	printf("%d", cnt);

	return 0;
}