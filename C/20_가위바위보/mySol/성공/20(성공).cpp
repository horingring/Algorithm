#include <stdio.h>
using namespace std;

int main(){
	int n, sub;
	char result;
	scanf("%d", &n);
	int a[n], b[n];
	
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(int i=0; i<n; i++){
		scanf("%d", &b[i]);
	}
	
	for(int i=0; i<n; i++){
		sub = a[i] - b[i];
		if(sub == 0) result='D';
		else if(sub==1 || sub==-2) result='A';
		else if(sub==-1 || sub==2) result='B';
		printf("%c\n", result);
	}
	
	
	
	return 0;
}

