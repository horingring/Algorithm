#include <stdio.h>
#include <stack>
using namespace std;

int main(){
	stack<int> s;
	char c;
	
	scanf("%c", &c);
	if(c==')'){
		printf("NO");
		return 0;
	}
	
	while(c!='\0'){
		if(c=='(') s.push(1);
		else if(c==')'){
			if(s.empty()){
				printf("NO");
				return 0;
			} else {
				s.pop();
			}
		}
		
		scanf("%c", &c);
	}
	
	if(s.empty()) printf("YES");
	else printf("NO");
	
	return 0;
}
