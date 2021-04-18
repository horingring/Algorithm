#include <stdio.h>
using namespace std;

int main(){
	int n, cnt=2;
	bool isPrime;
	
	scanf("%d", &n);
	
	if(n==2){
		cnt = 1;
		printf("%d", cnt);
		return 0;
	}
	else if(n==3 || n==4){
		cnt = 2;
		printf("%d", cnt);
		return 0;
	}
	
	for(int i=5; i<=n; i+=2){
		if(i%3==0) continue; 
		isPrime = true;
		for(int j=5; j<i; j++){
			if(i%j == 0){
				isPrime=false;
				break;
			}
		}
		if(!isPrime) continue;
		cnt++;
	}
	printf("%d", cnt);
	
	return 0;
}

