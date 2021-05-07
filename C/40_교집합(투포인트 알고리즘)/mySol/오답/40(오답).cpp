#include <stdio.h>
using namespace std;

int main(){
	int n, m, iA=0, iB=0, iC=0, p1, p2;
	scanf("%d", &n);
	
	//a배열 입력
	int a[n]={0,};
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	//b배열 입력
	scanf("%d", &m);
	int b[m]={0,};
	for(int i=0; i<m; i++){
		scanf("%d", &b[i]);
	}
	//c배열 초기화
	int c[n+m] = {0,};
	for(int i=0; i<n+m; i++){
		c[i] = -2147000000;
	}
	
	//각 배열을 가리키는 포인터
	p1=a[iA];  // p1=a[0]
	p2=b[iB];  // p2=b[0]
	
	while(iA <= n && iB <= m){  //각 포인터의 인덱스가 각각 n, m값이 되면 루프 종료
		//두 값이 같을 경우
		if(p1==p2){
			c[iC++]=p1;
			p1 = a[++iA];
			p2 = b[++iB];
		} else if(p1<p2){	//두 값이 다를 경우
			p1 = a[++iA];
		} else if(p1>p2){
			p2 = b[++iB];
		} 
	}
	
	//출력
	for(int i=0; c[i]!=-2147000000; i++){
		printf("%d ", c[i]);	
	}

	return 0;
}

