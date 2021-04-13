#include <stdio.h>
using namespace std;
int main(){
	char a[100];
	gets(a);
	
	for(int i=0; a[i]!='\0'; i++){
		if(a[i]>=97 && a[i]<=122){
			printf("%c", a[i]);
		}
		else if(a[i]>=65 && a[i]<=90){
			printf("%c", a[i]+32);
		}
	}
	
	return 0;
}

