#include <iostream>
using namespace std;

int main() {
	char charac[51];
	int a[51] = { 0, };  // 배열 a는 charac으로부터 추출한 숫자 하나하나가 담겨있는 배열
	int i, p = 0, num = 0, deci = 1, cnt = 0;

	cin >> charac;

	/* 숫자추출 */
	for (i = 0; charac[i] != '\0'; i++) {
		if (charac[i] >= 48 && charac[i] <= 57) {
			a[p++] = charac[i] - 48;  // 포인터(p)를 이용해 추출한 숫자를 배열 a에 하나하나 넣음
		}
	}

	/* num 구하기 */
	for (i = p - 1; i >= 0; i--) {  // 포인터(p)를 이용해 a의 뒤에서부터 숫자를 가져와 num을 구해 나간다
		num += a[i] * deci;
		deci *= 10;
	}

	cout << num << "\n";

	/* 약수의 갯수 구하기 */
	for (i = 1; i <= num; i++) {
		if (num % i == 0) cnt++;
	}

	cout << cnt;

	return 0;
}
