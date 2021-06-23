#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> map[11];  // 노드가 1~10 범위에서만 유효 (* 11 이상의 수가 나온다면 map 대괄호 안의 숫자를 높여줘야 함)
vector<int> visit;
queue<int> q;

void bfs(int x) {
	/* 방문 및 처리(*여기에서는 출력) */
	visit[x] = 1;
	printf("%d ", x);

	/* 다음 depth 대기처리 : 인접노드 중 방문하지 않은(* 이 경우 다음 depth) 노드를 q에 push */
	for (int j = 0; j < map[x].size(); j++) {
		if (!visit[map[x][j]]) {
			q.push(map[x][j]);
		}
	}

	/* 처리가 끝난 현재 노드 q에서 pop */
	q.pop();

	/* 순서대로 대기 중인 다음 노드 bfs */
	while (!q.empty()) {
		bfs(q.front());
	}
}

int main() {
	int m, a, b;
	scanf_s("%d %d", &n, &m);
	visit = vector<int>(n + 1, 0);

	for (int i = 1; i <= m; i++) {
		scanf_s("%d %d", &a, &b);
		map[a].push_back(b);
		map[b].push_back(a);  // 무향 그래프이므로, 그 반대로도 인접 리스트에 push_back
	}

	q.push(1);  // 사전작업 : 첫 노드를 q에 넣어줌
	bfs(1);  // bfs 실행

	return 0;
}