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
		/* 탈락 왕자들의 수가 n과 같아지면 끝 */
		if (q.size() == n) {
			printf("%d\n", q.back());  // 공주를 구하러 가게 될 왕자
			/* 확인용. 탈락 왕자 순서 확인 */
			while (!q.empty()) {
				printf("%d ", q.front());
				q.pop();
			}
			return 0;
		}

		/* 탈락한 왕자인 경우 : 스킵 */
		if (a[p] == 1) {
			p++;
			if (p > n) p = 1;  // n번째 왕자였을 경우 -> 다시 1번째로
			continue;
		}

		/* 아직 탈락하지 않은 왕자인 경우 */
		if (cnt != k) {  // 탈락번호 k가 아닌 경우
			p++;
			if (p > n) p = 1;
			cnt++;
		}
		else if (cnt == k) {  //탈락번호 k에 걸린 경우
			a[p] = 1;
			q.push(p);  // 탈락왕자 명단인 q에 push
			p++;
			if (p > n) p = 1;
			cnt = 1;
		}
	}


	return 0;
}