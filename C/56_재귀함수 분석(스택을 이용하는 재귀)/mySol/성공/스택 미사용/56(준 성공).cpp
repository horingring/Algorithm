#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

void jaegui(int num, int n){
	printf("%d ", num);
	num++;
	if(num != n){
		jaegui(num, n);		// 재귀함수 사용
	} else {
		printf("%d", n);
	}
	return;
}

int main(){
	int n;
	scanf("%d", &n);
	
	jaegui(1, n);
	
	return 0;
}

