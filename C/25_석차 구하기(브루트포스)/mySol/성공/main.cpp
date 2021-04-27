#include <stdio.h>
using namespace std;

int main(){
	int n, temp, cnt, cntStack=1;;
	scanf("%d", &n);
	//a[i][0]==점수  //a[i][1]==석차  //(*b도 같은 구조)
	int a[n][2] = {0,};	// 원본 데이터(점수의 배열)
	int b[n][2] = {0,}; // 정렬 데이터(내림차순)
	
	for(int i=0; i<n; i++){
		scanf("%d", &a[i][0]);
		b[i][0] = a[i][0];
	}
	
	//b 정렬
	for(int i=0; i<n-1; i++){
		temp = 0;
		for(int j=i+1; j<n; j++){
			if(b[i][0]<b[j][0]){
				temp = b[i][0];
				b[i][0] = b[j][0];
				b[j][0] = temp;
			}
		}
	}
	
	
	//b 순위 구하기
	for(int i=0; i<n; i++){
		if(b[i][1] != 0){
			continue;
		}
		cnt = cntStack;
		b[i][1] = cnt;
		
		for(int j=i+1; j<n; j++){
			if(b[i][0] == b[j][0]){
				b[j][1] = cnt;
				cntStack++;
				continue;
			}
		}
		cntStack++;
	}
	
	
	//b와 a를 비교 -> a에 순위 주기
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(b[i][0] == a[j][0]){
				if(a[j][1] == 0){
					a[j][1] = b[i][1];
					break;
				}
				
			}
		}
	}
	
	
	//a 순위 출력
	for(int i=0; i<n; i++){
		printf("%d ", a[i][1]);		
	}

	

	return 0;
}

