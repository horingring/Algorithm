#include <iostream>
using namespace std;

int main() {
	int n, input, min = 2147000000, max = -2147000000;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input < min) min = input;
		if (input > max) max = input;
	}

	cout << max - min;

	return 0;
}
