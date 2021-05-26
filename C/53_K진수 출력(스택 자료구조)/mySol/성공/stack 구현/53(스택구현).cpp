#include <stdio.h>
//#include <vector>
//#include <stack>
using namespace std;

int p=50;  // 포인터
int stack[50];  //스택

bool isEmpty(){  /* isEmpty 함수 */
	bool empty = false;
	if(stack[0]==-1 && stack[49]==-1){
		empty = true;
	}
	
	return empty;
}

void push(int num){  /* push 함수 */
	p--;
	stack[p] = stack[0];
	stack[0] = num;
	return;
}

int top(){  /* top 함수 */
	return stack[0];
}

void pop(){  /* pop 함수 (remove 함수) */
	if(isEmpty()) return;
	
	stack[0] = stack[p];
	stack[p] = -1;
	p++;
	
	if(p==51) p=50;
	
	return;
}

// main
int main(){
	int n, k;
	char hexChar;
	scanf("%d %d", &n, &k);
	
	// 반드시 스택을 -1로 초기화해야 함
	for(int i=0; i<50; i++){
		stack[i] = -1;
	}
	
	while(n>=k){
		push(n%k);
		n /= k;
	}
	
	printf("%d", n);
	while(isEmpty() == false){
		if(top()>=10){
			switch(top()){
				case 10:
					hexChar = 'A';
					break;
				case 11:
					hexChar = 'B';
					break;
				case 12:
					hexChar = 'C';
					break;
				case 13:
					hexChar = 'D';
					break;
				case 14:
					hexChar = 'E';
					break;	
				case 15:
					hexChar = 'F';
					break;
			}	
			printf("%c", hexChar);
		} else printf("%d", top());
		pop();
	}
	
	return 0;
}

