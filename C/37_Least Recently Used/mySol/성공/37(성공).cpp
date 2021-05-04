#include <stdio.h>
using namespace std;

int main(){
	// s:캐시메모리의 크기  n:처리할 작업의 수
	int s, n, input;
	scanf("%d %d", &s, &n);
	// a:캐시메모리
	int a[s]={0,};
	
	for(int i=0; i<n; i++){
		// 현재 처리 작업을 임시 저장소인 input에 저장
		scanf("%d", &input);

		/* 현재 처리할 작업이 이미 캐시메모리에 존재하는지 검사 */
		int j;	//존재한다면 그 인덱스 값(j)을 구하기
		for(j=0; j<s; j++){
			if(input == a[j]) break;
		}
		
		// j==s 이면 작업이 캐시메모리에 존재하지 않는다는 뜻.
		// 반대로 j!=s 이면 작업이 캐시메모리에 존재한다는 뜻.

		// 캐시메모리에 작업이 이미 존재할 경우
		if(j!=s){
			// a[0] ~ a[j-1]까지 작업들을 한칸 뒤로 밀어내기
			for(int k=j; k>=1; k--){
				a[k] = a[k-1];
			}
			a[0] = input;
		}
		// 캐시메모리에 작업이 존재하지 않을 경우 
		else if(j==s){
			// 캐시메모리의 모든 작업들을 한칸 뒤로 밀어내기
			for(int k=s-1; k>=1; k--){
				a[k] = a[k-1];
			}
			a[0] = input;
		}
	}
	
	for(int i=0; i<s; i++){
		printf("%d ", a[i]);
	}

	return 0;
}

