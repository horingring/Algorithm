#include <stdio.h>
using namespace std;

int main(){
	int n, k, max=-2147000000, sum=0;
	
	scanf("%d %d", &n, &k);
	
	int a[n] = {0,};
	
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}

	for(int i=0; i<k; i++){
		sum += a[i];
	}
	if(max < sum) max=sum;
	
	for(int i=1; i<n-k+1; i++){
		sum = sum - a[i-1] + a[i+k-1];
		if(max < sum) max=sum;
	}
	
	printf("%d", max);
	
	return 0;
}

