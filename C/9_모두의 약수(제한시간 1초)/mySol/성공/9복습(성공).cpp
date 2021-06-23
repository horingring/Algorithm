#include <stdio.h>
#include <vector>
using namespace std;

int main() {
	int n;
	scanf_s("%d", &n);
	vector<int> a(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; i * j <= n; j++) {
			a[i * j]++;
		}
	}

	for (int k = 1; k <= n; k++) {
		printf("%d ", a[k]);
	}

	return 0;
}