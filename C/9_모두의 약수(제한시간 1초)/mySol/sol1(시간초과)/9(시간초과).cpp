#include <stdio.h>
using namespace std;

int main(){
	int N, i, j, k;
	
	scanf("%d", &N);
	
	for(i=1; i<=N; i++){
		k=0;
		for(j=1; j<=i; j++){
			if(i%j==0) {
				k++;
			}
		}
		printf("%d ", k);
	}
	
	return 0;
}

