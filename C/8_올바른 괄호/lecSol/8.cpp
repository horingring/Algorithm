#include <stdio.h>
using namespace std;

int main(){
	char a[31];
	int i, cnt=0;
	
	scanf("%s", a);
	
	for(i=0; a[i]!='\0'; i++){
		if(a[i]=='(') cnt++;
		else cnt--;
		
		if(cnt<0) break;
	}
	
	if(cnt==0) printf("YES\n");
	else printf("NO\n");
	
	return 0;
}

