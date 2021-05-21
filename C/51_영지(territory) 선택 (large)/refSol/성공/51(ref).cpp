#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int H, W, tH, tW, max=-1, sum;
	int iTmp, jTmp;
	scanf("%d %d", &H, &W);
	vector<vector<int>> a(H+1, vector<int>(W+1, 0));
	vector<vector<int>> b(H+1, vector<int>(W+1, 0));
	
	// 모든 영지(배열 a) 입력
	for(int i=1; i<=H; i++){
		for(int j=1; j<=W; j++){
			scanf("%d", &a[i][j]);
		}
	}
	
	// (0행 0렬)~(i행j열)까지의 오랜지나무 수의 합계 구하기(배열 b)
	for(int i=1; i<=H; i++){
		for(int j=1; j<=W; j++){
			if(i==1){
				b[i][j] = b[i][j-1]+a[i][j];	
			} 
			else if(j==1){
				b[i][j] = b[i-1][j]+a[i][j];	
			} 
			else{
				b[i][j] = b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j];	
			} 
		}
	}
	
	/*
	// b 배열 출력
	printf("\nb배열 출력\n");
	
	for(int i=1; i<=H; i++){
		for(int j=1; j<=W; j++){
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	*/

	// 입력 : 하사받는 영지의 세로, 가로 크기(tH, tW)
	scanf("%d %d", &tH, &tW);

	// b배열 이용하여 오랜지나무의 최대 수 구하기
	for(int i=1; i+tH-1<=H; i++){
		for(int j=1; j+tW-1<=W; j++){
			sum=0;
			if(i==1){
				sum = b[i+tH-1][j+tW-1]
					- b[i+tH-1][j-1];
			}else if(j==1){
				sum = b[i+tH-1][j+tW-1]
					- b[i-1][j+tW-1];
			}else{
				sum = b[i+tH-1][j+tW-1]
					- b[i-1][j+tW-1]
					- b[i+tH-1][j-1]
					+ b[i-1][j-1];
			}
			if(max<sum){
				max=sum;
				iTmp = i;
				jTmp = j;
			}
		}
	}
	
	// 출력 : 오랜지나무의 최댓값, 그곳의 시작좌표(i행 j열)
	printf("%d, ( %d행 %d열 )", max, iTmp, jTmp);
	
	return 0;
}

