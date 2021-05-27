#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

int main(){
	char a[31];	
	scanf("%s", &a);
	
	stack<int> s;
	
	for(int i=0; a[i]!='\0'; i++){
		if(a[i] == '('){
			s.push(1);
		} else if(a[i] == ')'){
			if(s.empty()){		// ')'인데 먼저 표기된 '('가 없는 경우  --->  반드시 "NO"
				printf("NO");
				return 0;
			} else {
				s.pop();
			}
		}
	}
	
	if(s.empty()){
		printf("YES");
	} else {
		printf("NO");
	}
	
	return 0;
}

