#include <stdio.h>
using namespace std;

int main(){
	int n, num1, num2, cnt=1, max=-2147000000;
	
	scanf("%d\n%d", &n, &num1);
	
	for(int i=0; i<n-1; i++){
		scanf("%d", &num2);
		if(num1<=num2){
			cnt++;
			if(max<cnt) max=cnt;
		} else	cnt=1;
		num1=num2;
	}
	
	printf("%d", max);
	
	return 0;
}

