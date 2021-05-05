#include <stdio.h>
using namespace std;

int main(){
	int n, cnt;
	scanf("%d", &n);
	int a[n+1]={0,}, b[n]={0,};
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	
	for(int i=1; i<=n; i++){
		cnt=a[i];
		int j=0;
		while(cnt>=0){
			//b[j]에 아무 수도 없을 경우에만 cnt-- 해준다. 수가 있을 경우에는 j++만 해준다.
			//이는 b[j]에 이미 자리잡은 수가 있다면, 그것은 i의 순서 상 반드시 자신보다 작은 수일 것이고,
			//때문에 현재 i의 자리는 b의 다음 index로 넘어가야 한다.
			if(b[j]==0) cnt--;
			j++;
		}
		//위 while문을 반드시 1번 이상은 돌게 되어 있으므로, j>=1이게 된다. (왜냐하면 반드시 cnt>=0 이기에)
		//따라서 b[j-1] = i로 해준다.
		b[j-1]=i;
	}
	
	for(int i=0; i<n; i++){
		printf("%d ", b[i]);
	}

	return 0;
}

