#include <iostream>
using namespace std;

int a[11] = { 0, };	//원본
int b[11] = { 0, }; //a를 복사
int n, m, cnt = 0;

void DFS(int x, int sum) {
	sum += b[x];  // 현재 level에 해당하는 숫자(양수/음수/없음) 더해주기
	if (x == n) {	// 마지막 level에 도달한 경우
		if (sum == m) {
			cnt++;
		}
		return;
	}

	b[x + 1] = a[x + 1];  // 해당 level의 값 : 원래 값 주기
	DFS(x + 1, sum);
	b[x + 1] *= -1;  // 해당 level의 음수 값 : 원래값 * -1
	DFS(x + 1, sum);
	b[x + 1] = 0;  // 해당 level의 숫자가 없는 경우 : 0
	DFS(x + 1, sum);
}

int main() {
	int sum = 0;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}

	DFS(0, sum);
	if (cnt == 0) cnt = -1;  // sum == m 인 경우가 아예 없는 경우, -1 출력

	cout << cnt;
}

