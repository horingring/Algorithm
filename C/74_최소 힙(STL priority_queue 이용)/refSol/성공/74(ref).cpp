#include <stdio.h>
#include <queue>
using namespace std;

int main() {
	int num;
	priority_queue<int, vector<int>, greater<int> > pQ;  // priority_queue<타입, container형태, 비교함수> 함수이름    // greater : 오름차순

	while (true) {
		scanf_s("%d", &num);

		if (num == -1) return 0;
		else if (num == 0) {
			if (pQ.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", pQ.top());
				pQ.pop();
			}
		}
		else {
			pQ.push(num);
		}
	}

	return 0;
}