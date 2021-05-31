#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

void A(int x){
	if(x<2) {
		printf("%d", x);
		return;	
	}
	A(x/2);
	printf("%d", x%2);
}

int main(){
	int n;
	scanf("%d", &n);
	
	A(n);
	
	return 0;
}

