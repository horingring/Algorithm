#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int sum, avg, currentAbsSub;
	int a[10]={0,};
	int minAbsSub[2] = {101,0};  //최소 절대 차(sub) : 행의 평균값(avg) vs 행의 각 수 -> 이 값이 가장 작아야 평균과 가장 가까운 수가 됨
	
	for(int i=1; i<=9; i++){
		// 1. 루프 진입 시 초기화
		sum = 0;
		avg = 0;
		minAbsSub[0] = 101;
		minAbsSub[1] = 0;
		
		// 2. 입력 & 합계구하기
		for(int j=1; j<=9; j++){
			scanf("%d", &a[j]);
			sum += a[j];
		}
		
		// 3. 평균 구하기 (*반올림 처리) & 출력
		if((sum%9)*10/9 >= 5){
			avg = sum/9 + 1;
		}else avg = sum/9;
		
		printf("%d ", avg);
		
		// 4. 평균과 가장 가까운 수 찾기 & 출력
		for(int j=1; j<=9; j++){
			// 현재 수 vs 평균 ---> 현재 절대 차
			if(avg>=a[j]){
				currentAbsSub = avg-a[j];
			}else currentAbsSub = a[j]-avg;
			
			// 최소 절대 차 vs 현재 절대 차 ---> 최소 절대 차, index 갱신
			if(minAbsSub[0]>currentAbsSub){
				minAbsSub[0] = currentAbsSub;
				minAbsSub[1] = j;
			}else if(minAbsSub[0]==currentAbsSub){
				if(a[minAbsSub[1]] <= a[j]){
					minAbsSub[1] = j;
				}
			}
		}
		printf("%d\n", a[minAbsSub[1]]);
	}
	
	return 0;
}

