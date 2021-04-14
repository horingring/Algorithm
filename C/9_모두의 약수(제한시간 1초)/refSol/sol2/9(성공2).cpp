#include <stdio.h>
using namespace std;

int main(){
	int N, i, j;
	scanf("%d", &N);
	int a[N+1]={0,};
	
	
	for(i=1; i<=N; i++){
		for(j=i; j<=N; j=j+i){
			a[j]++;
		}
		printf("%d " , a[i]);
	}
	
	return 0;
}

