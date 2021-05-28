#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

int main(){
	stack<int> s;
	int n, p1=1, p2=1, pr=0;	// p1: 배열 a에 대한 포인터    // p2: 배열 b에 대한 포인터    // pr: 배열 result에 대한 포인터
	scanf("%d", &n);
	int a[n+1]={0,}, b[n+1]={0,};	// 배열 a: 기차 출발역    //배열 b: 기차 도착역
	char result[61];	// 스택의 push/pop 정보인 'P'/'O'가 들어오는 배열
	
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	
	while(p2 <= n) {	// 배열 b가 다 차면 반복문 종료
		/* a에서 출발한 기차가 교차로(stack)에 들어옴 */
		s.push(a[p1]);
		result[pr++] = 'P';
		
		/* 모든 기차가 a역을 떠났을 때: 교차로에 남은 기차들 처리 */
		if(p1==n){
			while(!s.empty()){	// 교차로에 기차가 더이상 없을 때까지 반복
				if(p2 == s.top()){
					b[p2++] = s.top();
					s.pop();
					result[pr++] = 'O';
				} else {
					printf("impossible");
					return 0;
				}
			}
		} else {	/* a역에 기차가 아직 남았을 때 */
			/* 스택의 top과 다음 a에서 출발할 기차 번호 비교 */    // *스택의 top == 가장 최근에 교차로에 들어온 기차
			if(s.top() > a[p1+1]){	// 스택의 top의 번호가 더 클 경우.  --> 스택은 그대로, 다음 기차는 그 위에 push될 예정
				p1++;
			} else if(s.top() < a[p1+1]) {	// 다음 기차 번호가 더 클 경우.  --> 반드시 스택의 top 기차는 교차로를 빠져나가야 함. 이 때 2가지 경우로 나뉨
				if(p2 == s.top()){	// 1) 빠져나간 기차의 번호 num이 b역에 도착 시 제대로 된 순서 num으로 도착하는 경우 (*예 - 3번기차 == b역에 3번째로 도착)
					b[p2++] = s.top();
					s.pop();
					result[pr++] = 'O';
					p1++;
				} else {	// 2) 빠져나간 기차의 번호 num이 b역에 도착 시 원래 도착해야할 순서 num과 다른 경우 (*예 - 3번기차 -> b역에 2번째로 도착)
					printf("impossible");
					return 0;
				}
			}
		}
	}
	result[pr] = '\0';	// 스택의 push/pop 정보가 담긴 result 배열의 끝에 NULL문자 입력
	
	/* result 출력 */
	for(int i=0; result[i]!='\0'; i++){
		printf("%c ", result[i]);
	}
	
	return 0;
}

