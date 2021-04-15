#include <stdio.h>
using namespace std;

int main(){
	int n, k, cnt=1, supply=0, result;
	scanf("%d", &n),
	
	k = n;
	while(k/10 != 0){
		k /= 10;
		cnt++;
	}
	
	// get 1234... (supply)
	for(int i=0; i<cnt; i++){
		supply = supply*10 + i;
	}
	
	result = cnt*n - 9*supply;
	printf("%d", result);
	
	return 0;
}

