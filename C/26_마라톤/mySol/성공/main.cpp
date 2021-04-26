#include <stdio.h>
using namespace std;

int main(){
	int n, cnt=1;
	scanf("%d", &n);
	int a[n]={0,};
	
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	for(int i=0; i<n; i++){
		cnt=1;
		for(int j=0; j<i; j++){
			if(a[j]>=a[i]) cnt++;
		}
		printf("%d ", cnt);
	}
	
	
	return 0;
}

