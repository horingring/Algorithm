#include <stdio.h>

int a[100], b[100];	 // 배열 a : 원본배열    // 배열 b : a의 복사배열
int p1, p2, p3;

void merge(int left, int right, int mid) {
	/* 분할-정복 */
	if (left != right) {
	// 계속(재귀를 통해) 분할-정복 해 나간다.
	// * left와 right가 같아졌다는 것은, 더는 분할할 수 없는 상태가 되었다는 뜻. 그때는 더이상 merge함수를 호출하면 안된다.

		// 2부분 중 왼쪽 부분 병합정렬
		int childMid = (left + mid) / 2;
		merge(left, mid, childMid);  

		// 2부분 중 오른쪽 부분 병합정렬
		childMid = (mid + 1 + right) / 2;
		merge(mid + 1, right, childMid);  
	}

	/* 병합(merge) */
	p1 = left;  // p1 : 분할정복이 완료된 왼쪽부분의 포인터
	p2 = mid + 1;  // p2 : 분할정복이 완료된 오른쪽부분의 포인터
	p3 = left;	// p3 : 오름차순으로 정렬될 b에 대한 포인터

	while (p1 <= mid && p2 <= right) {    // 병합정렬 시 2부분 중 아무나 1부분이 먼저 사용 완료될 때까지 반복
		if (a[p1] > a[p2]) {
			b[p3++] = a[p2++];
		}
		else {
			b[p3++] = a[p1++];
		}
	}

	if (p1 > mid) {    // 2부분 중 아직 사용완료되지 않은 부분의 남은 숫자들을 b배열의 나머지 부분에 넣어줌 (p1부분이 먼저 완료 시)
		while (p2 <= right) {
			b[p3++] = a[p2++];
		}
	}
	else if (p2 > right) {    // 2부분 중 아직 사용완료되지 않은 부분의 남은 숫자들을 b배열의 나머지 부분에 넣어줌 (p2부분이 먼저 완료 시)
		while (p1 <= mid) {
			b[p3++] = a[p1++];
		}
	}

	/* 반영 */
	for (int i = left; i <= right; i++) {
		a[i] = b[i];  // 복사배열 b의 적용사항을 원본배열 a에 반영해준다
	}
}


int main() {
	int n, left, right, mid;
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
		b[i] = a[i];
	}

	left = 0;
	right = n - 1;
	mid = (left + right) / 2;
	merge(left, right, mid);

	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	return 0;
}