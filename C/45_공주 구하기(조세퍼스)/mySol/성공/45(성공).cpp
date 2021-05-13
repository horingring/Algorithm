#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, k, i, livingMan, cnt=0;
	scanf("%d %d", &n, &k);
	
	int a[n+1]={0,};
	for(int j=1; j<=n; j++){
		a[j] = j;
	}
	
	// livingMan == 남아있는 왕자
	livingMan=n;
	i=1;
	
	while(true){
		if(a[i] != -1){ //이미 빠진 왕자는 세지 않는다
			//먼저 cnt++
			cnt++;
			//cnt가 특정 숫자 k가 되면 해당 왕자는 빠짐
			if(cnt==k){
				a[i]=-1;
				livingMan -= 1;
				cnt=0;
				// 남아있는 왕자가 1명일 때
				if(livingMan == 1) {
					for(int j=1; j<=n; j++){
						if(a[j]!=-1){
							printf("%d", j);
							return 0;
						}
					}
				}
			}
		}
		if(i==n) i=1;  // 마지막 왕자를 체크했으면 다시 처음 왕자로 돌아가기
		else i++;  // 마지막 왕자가 아니면 그냥 다음 왕자로 넘어가기
	}
	

	return 0;
}

