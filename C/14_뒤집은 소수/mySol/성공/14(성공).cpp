#include <stdio.h>
using namespace std;

int reverse(int x){
	int reverse=0, deci=1;
	char a[7];
	sprintf(a, "%d", x);
	
	for(int i=0; a[i]!='\0'; i++){
		reverse = reverse + (a[i]-48)*deci;
		deci *= 10;
	}
	return reverse;
}

bool isPrime(int x){
	if(x==1) return false;
	for(int i=2; i<x; i++){
		if(x%i==0) return false;
	}
	return true;
}

int main(){
	int n, k, reK;
	scanf("%d ", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &k);
		reK = reverse(k);
		if(isPrime(reK)) printf("%d ", reK);
	}
	
	return 0;
}

