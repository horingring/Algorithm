#include <stdio.h>
#include <queue>
using namespace std;

int main() {
	priority_queue<int> pQ;
	// 아래 주석은 디버깅을 통해 push 할 때마다 pQ의 상태를 살펴본 것임
	pQ.push(3);		//pQ : 3
	pQ.push(2);		//pQ : 3 - 2
	pQ.push(5);		//pQ : 5 - 2 - 3
	pQ.push(-1);	//pQ : 5 - 2 - 3 - (-1)
	pQ.push(4);		//pQ : 5 - 4 - 3 - (-1) - 2
	pQ.push(2);		//pQ : 5 - 4 - 3 - (-1) - 2 - 2
	// push에 따른 이런 pQ의 변동은, 최대힙 자료구조의 레벨(depth) 별 순서와 아주 유사함
}