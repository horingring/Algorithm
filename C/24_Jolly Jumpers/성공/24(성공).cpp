#include <stdio.h>
using namespace std;

int main(){
	int n, sub=0, absSub;	//sub는 계산에 이용되므로 유지해야함. //absSub는 그 절댓값
	scanf("%d", &n);
	int a[n]={0,};
	int b[n]={0,};
	
	// a배열은 a[1]~a[n-1]까지 사용 (*a[0]은 사용하지 x)
	// absSub의 존재여부(있다면 후에 0이 됨)
	for(int i=1; i<n; i++){
		a[i] = i;
	}
	
	// b배열 : 수열의 각 수들
	for(int i=0; i<n; i++){
		scanf("%d", &b[i]);
	}
	
	// 첫 번째 sub는 먼저 계산
	sub = b[1]-b[0];
	if(sub < 0) absSub = sub*-1;
	else if(sub > 0) absSub = sub;
	else if(sub == 0){
		printf("NO");
		return 0;
	}
	
	if(absSub > n-1){
		printf("NO");
		return 0;
	}
	else if(absSub <= n-1) a[absSub]=0;
	
	// 두 번째 sub부터는 for문
	for(int i=2; i<n; i++){
		sub = b[i]-(sub+b[i-2]);
		
		if(sub < 0) absSub=sub*-1;
		else if(sub > 0) absSub=sub;
		else if(sub==0){
			printf("NO");
			return 0;
		}
		
		if(absSub > n-1){
			printf("NO");
			return 0;
		}
		else if(absSub <= n-1) a[absSub]=0;
	}
	
	// a배열 체크
	for(int i=1; i<n; i++){
		if(a[i]!=0){
			printf("NO");
			return 0;
		}
	}
	
	printf("YES");
	
	
	return 0;
}

