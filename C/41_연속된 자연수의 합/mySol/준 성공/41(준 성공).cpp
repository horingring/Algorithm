#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int n, cnt=0, sum;
	// n 입력
	scanf("%d", &n);
	
	// 1~n 사이의 연속된 자연수들의 합이 n이 되는 수들
	for(int i=1; 2*i<=n; i++){
		sum=0;
		
		for(int j=i; true; j++){
			sum += j;
			if(sum==n){
				cnt++;
				for(int k=i; k<j; k++){
					printf("%d + ", k);
				}
				printf("%d = %d\n", j, n);
				break;
			} else if(sum>n) break;		
		}
	}
	
	// cnt 출력
	printf("%d", cnt);

	return 0;
}

