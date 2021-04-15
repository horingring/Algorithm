#include <stdio.h>
using namespace std;

int getDeci(int cnt){
	int deci=1, i;
	for(i=1; i<cnt; i++){
		deci *= 10;
	}
	return deci;
}

int main(){
	int n, k, cnt=1, result;
	scanf("%d", &n),
	
	k = n;
	while(k/10 != 0){
		k /= 10;
		cnt++;
	}
	
	result = cnt*n -(cnt-1)*(getDeci(cnt)-1);
	printf("%d", result);
	
	return 0;
}

