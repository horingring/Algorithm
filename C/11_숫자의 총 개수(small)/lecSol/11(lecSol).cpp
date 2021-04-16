#include <stdio.h>
using namespace std;

int main(){
	int n, i, k, cnt=0;
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){
		k=i;
		while(k/10 > 0){
			k = k/10;
			cnt++;
		}
		cnt++;
	}
	
	printf("%d", cnt);
	
	return 0;
}

