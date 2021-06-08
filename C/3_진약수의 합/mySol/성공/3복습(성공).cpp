#include <stdio.h>

int main() {
	int n, tmp = 0, sum = 1;
	scanf("%d", &n);

	// 1을 제외한 최소약수 구하기
	for (int i = 2; i <= n; i++) {
		if (n % i == 0) {
			tmp = i;
			break;
		}
	}

	// 소수 처리
	if(tmp!=n) printf("1 + ");
	else {
		printf("1 = 1");
		return 0;
	}
	
	// 진약수의 합 및 계산과정 출력
	for (int i = tmp; i < n / tmp; i++) {
		if (n % i == 0) {
			sum += i;
			printf("%d + ", i);
		}
	}
	sum += n / tmp;
	printf("%d = %d", n / tmp, sum);

	return 0;
}
