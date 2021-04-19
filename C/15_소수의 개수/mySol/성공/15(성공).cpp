#include <stdio.h>
using namespace std;

int main(){
	int n, cnt=1;
	
	scanf("%d", &n);
	int a[n+1] = {0,};
	
	if(n==2){
		printf("%d", cnt);
		return 0;
	}
	
	for(int i=3; i<=n; i+=2){
		if(a[i]!=0) continue;
		
		cnt++;
		for(int j=1; i*j<=n; j++){
			a[i*j]++;
		}
	}
	
	printf("%d", cnt);
	
	
	return 0;
}

