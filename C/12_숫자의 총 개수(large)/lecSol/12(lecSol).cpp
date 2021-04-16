#include <stdio.h>
using namespace std;

int main(){
	int n, sum=0, cnt=1, d=9, res=0;
	
	scanf("%d", &n);
	
	while(sum+d < n){
		res = res + cnt*d;
		sum = sum + d;
		cnt++;
		d = d*10;
	}
	
	res = res + cnt*(n-sum);
	
	printf("%d", res);
	
	
	return 0;
}

