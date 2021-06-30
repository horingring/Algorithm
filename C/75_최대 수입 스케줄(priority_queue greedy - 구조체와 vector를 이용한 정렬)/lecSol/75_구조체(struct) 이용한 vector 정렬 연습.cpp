#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Loc {  // 구조체 정의
	int x, y, z;  // 구조체의 멤버변수
	Loc(int a, int b, int c) {  // 구조체 생성자
		x = a;
		y = b;
		z = c;
	}
	bool operator<(const Loc& b)const {  // 연산자 오버로딩 ( : 두 객체의 크기 비교할 때 사용 )  // 상수 멤버함수
		if (x != b.x) return x < b.x;  // 두 구조체 안의 x끼리 비교 ( * 이 경우 오름차순 )
		if (y != b.y) return y < b.y;  // y끼리 비교 ( * x가 같은 경우 )
		if (z != b.z) return z < b.z;  // z끼리 비교 ( * x, y까지 다 같은 경우 )
	}
};

int main() {
	vector<Loc> XY;  // 사용자 정의 구조체 Loc 타입만 들어갈 수 있는 vector 선언
	XY.push_back(Loc(2, 3, 5));  // 생성자 통해 Loc객체 생성하여 XY vector에 push_back
	XY.push_back(Loc(3, 6, 7));
	XY.push_back(Loc(2, 3, 1));
	XY.push_back(Loc(5, 2, 3));
	XY.push_back(Loc(3, 1, 6));
	sort(XY.begin(), XY.end());  // XY vector 정렬 (이 때 구조체의 operator 함수가 적용됨)
	for (auto pos : XY) cout << pos.x << " " << pos.y << " " << pos.z << endl;

	return 0;
}