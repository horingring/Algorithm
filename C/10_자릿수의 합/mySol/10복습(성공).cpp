#include <stdio.h>

int digit_sum(int x) {
	int sum = 0;

	while (x != 0) {
		sum += x % 10;
		x /= 10;
	}
	
	return sum;
}

int main() {
	int n, num, max = -1, maxNum = 0;

	scanf_s("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &num);

		if (max < digit_sum(num)) {
			max = digit_sum(num);
			maxNum = num;
		}
		else if (max == digit_sum(num)) {
			if (maxNum < num) {
				maxNum = num;
			}
		}
	}

	printf("%d", maxNum);

	return 0;
}