#include <stdio.h>
#include <queue>
using namespace std;

int main() {
	int num;
	priority_queue<int> pQ;  // 기본 priority_queue (내림차순)

	while (true) {
		scanf_s("%d", &num);

		if (num == -1) return 0;
		else if (num == 0) {
			if (pQ.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", -pQ.top());  // 출력 시 -1을 곱해줌
				pQ.pop();
			}
		}
		else {
			pQ.push(-num);  // pQ에 push 시 -1을 곱해줌
		}
	}

	return 0;
}