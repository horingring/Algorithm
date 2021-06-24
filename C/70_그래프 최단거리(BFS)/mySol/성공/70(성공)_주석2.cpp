#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> map[21];
vector<int> qIn;  // queue에 해당노드가 1번이라도 들어올 시 0->1로 바뀜. 그동안 써왔던 visit 대신 이것을 사용함
vector<int> minCourse;  // 1번부터 각 노드까지 최단 간선의 수
queue<int> q;

void bfs(int x, int depth) {
	minCourse[x] = depth-1;  // 예 : 노드 1이 1depth이고 노드 5가 3depth라 했을 때, 1->5로 가는 최단 간선 수는 3-1=2 라고 할 수 있다

	int flag = 0;  // flag를 두는 이유 : 한 번도 queue에 들어가지 않은 인접노드의 유무를 체크하기 위해서

	for (int k = 0; k < map[x].size(); k++) {
		if (!qIn[map[x][k]]) {
			q.push(map[x][k]);
			qIn[map[x][k]] = 1;  // q에 해당 노드를 push했다면, qIn에도 체크한다.
			flag++;
		}
	}
	q.pop();
	if (flag == 0) return;  // 인접노드 중 갈 수 있는 노드가 없다면 여기서 return한다. 
							// "q에 이미 들어가 있는 노드이지만 아직 방문하지 않은 노드를 먼저 방문하는 것"을 막기 위함.

	// 여기부터는 다음 노드를 방문해도 된다.
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
	qIn[1] = 1;  // q에 해당 노드를 push했다면, qIn에도 체크한다.

	bfs(1, 1);

	for (int i = 2; i <= n; i++) {
		printf("%d : %d\n", i, minCourse[i]);
	}

	return 0;
}
