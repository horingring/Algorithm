#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

int e;
vector<int> jump = { -1, 1, 5 };

void bfs(int s, int d) {
	if (s == e) {
		printf("%d", d - 1);
		exit(0);
	}

	int min = 2147000000;
	int s2;
	int s2temp;
	for (int i = 0; i < jump.size(); i++) {
		s2temp = s + jump[i];
		int distance = abs(e - s2temp);
		if (min > distance) {
			min = distance;
			s2 = s2temp;
		}
	}

	s = s2;
	bfs(s, ++d);
}

int main() {
	int s;
	scanf_s("%d %d", &s, &e);

	bfs(s, 1);

	return 0;
}