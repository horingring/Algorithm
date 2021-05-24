#include <stdio.h>
#include <vector>
#include <stack>	//include stack stl
using namespace std;

int main(){
	int n, k;
	char hexChar;
	scanf("%d %d", &n, &k);
	
	stack<int> s;
	
	while(n>=k){
		s.push(n%k);  // stack에 push
		n /= k;
	}
	
	printf("%d", n);
	while(s.empty() == false){  // stack에 데이터가 들어있으면 아래를 반복
		if(s.top()>=10){  // 16진수의 경우
			switch(s.top()){
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
		} else printf("%d", s.top());
		s.pop();  // stack 제일 위 데이터 제거
	}
	
	return 0;
}

