#include <stdio.h>
using namespace std;

int main(){
	int n, k, max=-2147000000, sum;
	
	scanf("%d %d", &n, &k);
	
	int a[n] = {0,};
	
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}

	for(int i=0; i<n-k+1; i++){
		sum = 0;
		for(int j=i; j<i+k; j++){
			sum += a[j];
		}
		if(max < sum) max=sum;
	}
	
	printf("%d", max);
	
	return 0;
}

