#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

int e;
vector<int> jump = { -1, 1, 5 };

void bfs(int s, int d) {
	/* 도달한 곳에 송아지 있는지 확인 */
	if (s == e) {
		printf("%d", d - 1);
		exit(0);
	}

	/* 송아지가 없음 -> 3가지 경우 중 송아지와 가장 가까워지는 경우를 선택 */
	int min = 2147000000;
	int s2;  // s는 변하면 안되므로, s의 후보인 s2
	int s2temp;  // 현재 위치에서 다음 위치로 갔을 때 예상되는 위치
	for (int i = 0; i < jump.size(); i++) {
		s2temp = s + jump[i];
		int distance = abs(e - s2temp);  // 송아지와의 거리비교 (*절댓값 이용)
		if (min > distance) {
			min = distance;
			s2 = s2temp;
		}
	}

	s = s2;

	/* 그 가까운 경로로 가서 다시 송아지 탐색 */
	bfs(s, ++d);
}

int main() {
	int s;
	scanf_s("%d %d", &s, &e);

	bfs(s, 1);

	return 0;
}