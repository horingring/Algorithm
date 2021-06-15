#include <stdio.h>
#include <vector>
using namespace std;

int n, cnt = 0;
vector < vector <int> > a;
vector <int> visit;
vector <int> order(1, 0);  // <--- 바뀐부분

void DFS(int x) {
	visit[x] = 1;
	order.push_back(x);  // <--- 바뀐부분

	if (x == n) {
		cnt++;
		//바뀐부분(여기부터)
		for (int k = 1; k < order.size(); k++) {
			printf("%d ", order[k]);
		}
		//바뀐부분(여기까지)
		printf("\n");
		visit[x] = 0;
		order.pop_back();  // <--- 바뀐부분
		return;
	}
	else {
		for (int j = 1; j <= n; j++) {
			if (a[x][j] && !visit[j]) {
				DFS(j);
			}
		}
	}

	visit[x] = 0;
	order.pop_back();  // <--- 바뀐부분
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