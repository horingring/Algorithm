#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, k;
	int cP, nP, lP, nthP=0;
	int tmp, tmpCnt;
	//cP : currentProcess. 현재 처리중인(처리할) 작업
	//nP : nextProcess. 다음에 처리할 작업
	//lP : leftProcess. 남은 처리작업의 수
	//nthP : nthProcess. n번째(*이 문제의 경우 n-1 ~ n초 동안의) 처리

	scanf("%d", &n);
	int a[n+1] = {0,};
	
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	
	scanf("%d", &k);  //정전이 일어난 시간
	
	lP = n;
	cP = 1;
	
	while(lP != 0){
		if(a[cP] != 0){  //현재 처리할 작업이 완료된 작업이 아닌 경우
			/* 1. 현재 작업 처리 (*처리 시 해당 작업 -1초) */
			a[cP]--;  

			/* 2. 완전히 처리되었는지 검사 */
			if(a[cP]==0) lP--;
			
			/* 3. 다음 작업(nP) 구하기 */
			tmp = cP;
			tmpCnt = n;
			while(true){
				if(tmpCnt == 0){  //정전 되기 전에 모든 작업이 처리된 경우
					printf("-1");
					return 0;
				}
				if(tmp==n) tmp=1;  //배열순서상 마지막 작업이면 다시 1번째 작업으로
				else tmp++;
				if(a[tmp]==0){
					tmpCnt--;
					continue;
				}else if(a[tmp]!=0){  //다음 작업(nP)을 찾은 경우
					nP = tmp;
					break;
				}
			}
			
			/* 4. 위 작업들이 끝나는 순간 nth 초가 됨 */
			nthP++;

			/* 5. nth초에 정전이 났을 경우 다음 작업 출력 */
			if(nthP == k){
				printf("%d", nP);
				return 0;
			}
		}
		cP = nP;
	}
	

	return 0;
}

