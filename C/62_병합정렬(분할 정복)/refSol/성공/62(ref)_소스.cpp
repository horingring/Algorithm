#include <stdio.h>

int a[100], b[100];
int p1, p2, p3;

void merge(int left, int right, int mid) {
	if (left != right) {
		int childMid = (left + mid) / 2;
		merge(left, mid, childMid);

		childMid = (mid + 1 + right) / 2;
		merge(mid + 1, right, childMid);
	}

	p1 = left;
	p2 = mid + 1;
	p3 = left;

	while (p1 <= mid && p2 <= right) {
		if (a[p1] > a[p2]) {
			b[p3++] = a[p2++];
		}
		else {
			b[p3++] = a[p1++];
		}
	}

	if (p1 > mid) {
		while (p2 <= right) {
			b[p3++] = a[p2++];
		}
	}
	else if (p2 > right) {
		while (p1 <= mid) {
			b[p3++] = a[p1++];
		}
	}

	for (int i = left; i <= right; i++) {
		a[i] = b[i];
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