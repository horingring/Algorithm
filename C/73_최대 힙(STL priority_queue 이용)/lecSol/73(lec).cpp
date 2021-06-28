#include <stdio.h>
#include <queue>
using namespace std;

int main() {
	int num;
	priority_queue<int> pQ;

	while (true) {
		scanf_s("%d", &num);

		/* 입력값이 -1인 경우 : 종료 */
		if (num == -1) return 0;

		/* 입력값이 0인 경우 */
		if (num == 0) {
			if (pQ.empty()) printf("-1");  // 노드가 존재하지 않는 경우 : -1 출력
			else {                         // 노드 존재 시 : 루트노드 출력 후 pop
				printf("%d\n", pQ.top());
				pQ.pop();
				continue;
			}
			
		}

		/* 완전이진트리 방식으로 노드 삽입 */
		pQ.push(num);
	}

	return 0;
}