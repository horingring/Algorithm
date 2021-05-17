#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, bongwoori=0;
	scanf("%d", &n);
	// (n+2) X (n+2) 개의 이차원 벡터 a 생성 및 초기화
	vector<vector<int>> a(n+2, vector<int>(n+2, 0));
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(a[i][j]>a[i-1][j]  //상
			&& a[i][j]>a[i+1][j]  //하
			&& a[i][j]>a[i][j-1]  //좌
			&& a[i][j]>a[i][j+1]){  //우
				bongwoori++;
			}
		}
	}
	
	printf("%d", bongwoori);
	
	return 0;
}

