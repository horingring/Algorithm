#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, k, cnt = 1, p = 1;
	scanf_s("%d %d", &n, &k);
	vector<int> a(n + 1, 0);
	queue<int> q;

	while (true) {
		if (q.size() == n) {
			printf("%d\n", q.back());
			while (!q.empty()) {
				printf("%d ", q.front());
				q.pop();
			}
			return 0;
		}

		if (a[p] == 1) {
			p++;
			if (p > n) p = 1;
			continue;
		}

		if (cnt != k) {
			p++;
			if (p > n) p = 1;
			cnt++;
		}
		else if (cnt == k) {
			a[p] = 1;
			q.push(p);
			p++;
			if (p > n) p = 1;
			cnt = 1;
		}
	}


	return 0;
}