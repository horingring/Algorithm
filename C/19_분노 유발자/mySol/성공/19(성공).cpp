#include <stdio.h>
using namespace std;

int main(){
	int n, cnt=0;
	bool thisMan;
	
	scanf("%d", &n);
	int a[n] = {0,};
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	for(int i=0; i<n; i++){
		thisMan = true;
		if(i==n-1) thisMan=false;
		for(int j=i+1; j<n; j++){
			if(a[j]>=a[i]){
				thisMan = false;
				break;
			}
		}
		if(!thisMan) continue;
		else cnt++;
	}
	
	printf("%d", cnt);
	return 0;
}

