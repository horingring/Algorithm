#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int H, W, max=-1, sum, tH, tW;
	scanf("%d %d", &H, &W);
	vector<vector<int>> a(H+1, vector<int>(W+1, 0));
	
	//2차원 배열 입력
	for(int i=1; i<=H; i++){
		for(int j=1; j<=W; j++){
			scanf("%d", &a[i][j]);
		}
	}
	
	//2차원 배열 출력해보기
//	printf("\n");
//	
//	for(int i=0; i<=H; i++){
//		for(int j=0; j<=W; j++){
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}

	//오랜지나무의 수 최댓값 구하기(브루트포스)
	scanf("%d %d", &tH, &tW);
	for(int i=1; i<=H-tH+1; i++){
		for(int j=1; j<=W-tW+1; j++){
			sum=0;
			for(int k=i; k<=i+tH-1; k++){
				for(int l=j; l<=j+tW-1; l++){
					sum+=a[k][l];
				}
			}
			
			if(max < sum) max=sum;
		}
	}
	
	printf("%d", max);
	
	
	return 0;
}

