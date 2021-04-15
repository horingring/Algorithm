#include <stdio.h>
using namespace std;

int main(){
	int a[10]={0,};
	int n, maxCnt=-1, maxNum;
	
	scanf("%d", &n);
//	printf("%d ", n);
	
	while(n/10 > 0) {
		a[n%10]++;
		n = n/10;
	}
	a[n%10]++;
	
	for(int i=0; i<10; i++){
		if(maxCnt < a[i]){
			maxCnt = a[i];
			maxNum = i;
		}
		else if(maxCnt == a[i]){
			if(maxNum < i) maxNum = i;
		}
	}
	
	printf("%d", maxNum);
	
	return 0;
}

