#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int n, m, iA=0, iB=0, iC=0, p1, p2;  //교집합 구하기용 변수

	/* a배열 */
	//입력
	scanf("%d", &n);
	int a[n]={0,};
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	//정렬(by algorithm stl)
	sort(a, a+n);  //  <----------바뀐 부분
	
	/* b배열 */
	scanf("%d", &m);
	int b[m]={0,};
	for(int i=0; i<m; i++){
		scanf("%d", &b[i]);
	}
	//정렬(by algorithm stl)
	sort(b, b+m);  //  <----------바뀐 부분
	
	/* c배열(교집합 배열) */
	int c[n+m] = {0,};
	for(int i=0; i<n+m; i++){
		c[i] = -2147000000;
	}
	
	/* 포인터 */
	p1=a[iA];  // p1=a[0]
	p2=b[iB];  // p2=b[0]
	
	/* 교집합 구하는 알고리즘 */
	while(iA <= n && iB <= m){
		if(p1==p2){
			c[iC++]=p1;
			p1 = a[++iA];
			p2 = b[++iB];
		} else if(p1<p2){
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

