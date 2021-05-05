#include <stdio.h>
using namespace std;

int main(){
	int n, m;

	// 1번째 배열 입력
	scanf("%d", &n);
	int a[n]={0,};
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	// 2번째 배열 입력
	scanf("%d", &m);
	int b[m]={0,};
	for(int i=0; i<m; i++){
		scanf("%d", &b[i]);
	}
	
	// 3번째 배열 : a와 b가 새로 들어갈 배열
	// 3번째 배열 초기화 (2번째 배열의 원소 + 그외 초기값(-2147000000))
	// ( *그외 초기값을 -2147000000 으로 잡은 이유는,
	// 배열에 들어오는 수가 자연수가 아닐 수 있기 때문에(* 0일 수도 있기에) 이렇게 했다)
	int c[n+m] = {0,};
	for(int i=0; i<n+m; i++){
		if(i<m) c[i]=b[i];
		else c[i] = -2147000000;
	}
	
	// a -> c 배열로. c배열에 초기화된 b 원소와 비교하여 삽입정렬
	for(int i=0; i<n; i++){
		for(int j=0; j<n+m; j++){
			// a배열의 원소가 b배열의 모든 원소보다 큰 경우
			if(c[j]==-2147000000){
				c[j]=a[i];
				break;
			}else{
				if(a[i]>c[j]) continue;
				else{
					//삽입정렬을 위해 뒤의 원소들 모두 한 칸씩 뒤로 이동
					for(int k=m+n-1; k>=j+1; k--){
						c[k] = c[k-1];
					}
					//한칸씩 뒤로 이동이 다 완료되면 빈 자리에 a의 원소 넣어주기
					c[j] = a[i];
					break;
				}
			}
		}
	}
	
	for(int i=0; i<n+m; i++){
		printf("%d ", c[i]);	
	}
	

	return 0;
}

