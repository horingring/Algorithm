#include <stdio.h>
using namespace std;

int digit_sum(int x){
	int sum=0;
	while(x>=10){
		sum = sum + x%10;
		x = x/10;
	}
	sum = sum + x;
	return sum;
}

int main(){
	int N, i, maxSum=0, maxNum;
	
	scanf("%d", &N);
	int a[N]={0,};
	
	for(i=0; i<N; i++){
		scanf("%d", &a[i]);
	}
	
	for(i=0; i<N; i++){
		if(maxSum < digit_sum(a[i])){
			maxSum = digit_sum(a[i]);
			maxNum = a[i];
		}
		else if(maxSum == digit_sum(a[i])){
			if(maxNum <= a[i]){
				maxNum = a[i];
			}
		}
	}
	
	printf("%d", maxNum);
	
	return 0;
}

