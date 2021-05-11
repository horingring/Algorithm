#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	// n 입력
	int n, cnt=0, sum;
	scanf("%d", &n);
	
	// 1~n 사이의 연속된 자연수의 합이 n이 나오는 경우 구하기
	for(int i=n/2; i>0; i--){  //  <---------- 바뀐 부분 ( * i 초기값, 조건부, 증감부 )
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

