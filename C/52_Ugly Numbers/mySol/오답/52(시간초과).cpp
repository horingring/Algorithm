#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, num=2, tmpNum, index=2, j;
	bool isUN;
	scanf("%d", &n);
	vector<int> uN(n+1, 0);	//벡터 초기화 (0)
	
	uN[1] = 1;
	
	while(uN[n]==0){	//uN[n](n번째 Ugly Number)이 구해질때까지 반복
		tmpNum = num;
		j=2;
		isUN = true;
		
		while(tmpNum!=1){	//소인수분해
			if(tmpNum%j == 0){
				if(j>=7){	//Ugly Number는 2 || 3 || 5 만을 인수로 가져야 하므로, 인수가 7 이상이 되면 UN이 아님
					isUN = false;
					break;
				}
				tmpNum /= j;
			}
			else j++;
		}
		
		if(isUN){
			uN[index++] = num;
		}
		
		num++;
	}
	
	printf("%d", uN[n]);
	
	return 0;
}

