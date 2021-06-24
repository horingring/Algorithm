#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> map[21];
vector<int> qIn;  //queue에 해당 노드가 1번이라도 들어올 시 0->1로 바뀜
vector<int> minCourse;
queue<int> q;

void bfs(int x, int depth) {
	/* 처리 */
	minCourse[x] = depth-1;

	/* 인접노드 확인(인접노드 중 아직 q에 들어가지 않은 노드) */
	int flag = 0;

	for (int k = 0; k < map[x].size(); k++) {
		if (!qIn[map[x][k]]) {
			q.push(map[x][k]);
			qIn[map[x][k]] = 1;
			flag++;
		}
	}

	/* 처리가 끝난 현재 노드 q에서 pop */
	q.pop();

	/* 가도 되는 인접노드가 없을 시 return */
	if (flag == 0) return;

	/* 순서대로 대기 중인 다음 노드 bfs */
	depth++;
	while (!q.empty()) {
		bfs(q.front(), depth);
	}
}

int main() {
	int m, a, b;
	scanf_s("%d %d", &n, &m);
	qIn = vector<int>(n + 1, 0);
	minCourse = vector<int>(n + 1, 0);

	for (int i = 0; i < m; i++) {
		scanf_s("%d %d", &a, &b);
		map[a].push_back(b);
	}

	q.push(1);
	qIn[1] = 1;

	bfs(1, 1);

	for (int i = 2; i <= n; i++) {
		printf("%d : %d\n", i, minCourse[i]);
	}

	return 0;
}
