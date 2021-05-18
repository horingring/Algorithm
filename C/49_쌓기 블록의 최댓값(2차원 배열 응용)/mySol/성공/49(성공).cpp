#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, sum=0;
	scanf("%d", &n);
	
	vector<vector<int>> a(n, vector<int>(n,0));
	int input[n] = {0,};
	
	/* 1. 정면 */
	// 정면에서 본 블럭높이 입력
	for(int i=0; i<n; i++){
		scanf("%d", &input[i]);
	}
	
	// 위를 a 배열에 적용
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			a[i][j]=input[j];
		}
	}
	
	/* 2. 우측 */
	// 우측에서 본 블럭높이 입력
	for(int i=0; i<n; i++){
		scanf("%d", &input[i]);
	}
	
	// 우측에서 본 블럭높이 적용 (* a배열의 cell들의 값이 우측 블럭높이보다 클 경우에만 우측 블럭높이 적용)
	// * 아래 부분은 범위설정이 헷갈릴 수 있다.
	for(int i=n-1; i>=0; i--){
		for(int j=0; j<n; j++){
			if(a[i][j]>input[n-(i+1)]){
				a[i][j] = input[n-(i+1)];
			}
		}
	}
	
	// *** 위에서 본 높이(최대 개수) 출력 (*그냥 확인용으로 해봄)
	printf("\n위에서 본 높이(최대 개수)\n");	 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	// 3. 블럭의 최대 개수 구하기 & 출력
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			sum += a[i][j];
		}
	}

	printf("\n블럭의 최대 개수 : %d", sum);
	
	
	return 0;
}

