#include <stdio.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int a[n+1]={0,}, b[n+1]={0,};
	
	//a-점수의 배열  //b-개개인 석차의 배열
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		b[i] = 1;
	}
	
	//자신을 제외한 다른 사람의 점수와 비교하여,
	//다른사람의 점수가 더 크면
	//석차를 +1 시킨다.
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i==j) continue;
			if(a[i]<a[j]) b[i]++;
		}
	}
	
	for(int i=1; i<=n; i++){
		printf("%d ", b[i]);	
	}
	
	

	return 0;
}

