#include <stdio.h>
#include <stack>
using namespace std;

int main(){
	stack<int> s;
	char a[31] = {0,};
	
	scanf("%s", &a);
	
	for(int i=0; a[i]!='\0'; i++){
		if(i==0 && a[i]==')'){
			printf("NO");
			return 0;
		}
		if(a[i]=='(') s.push(1);
		else if(a[i]==')'){
			if(s.empty()){
				printf("NO");
				return 0;
			} else s.pop();
		}
	}
	
	if(s.empty()) printf("YES");
	else printf("NO");
	
	return 0;
}
