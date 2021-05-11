#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int n, input, first, last, mid;
	// n, input 입력
	scanf("%d %d", &n, &input);

	// a배열 초기화, 입력
	int a[n]={0,};
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	// a 정렬 (by algorithm stl)
	sort(a, a+n);
	
	// first, last 초기설정
	first = 0;
	last = n-1;
	
	while(true){
		mid = (first+last)/2;  //배열의 가운데 index인 mid 구하기
		// input과 a[mid]를 비교 -> 비교결과에 따라 first, last 바꿔주고, 같을 경우 해당 mid(index)가 정답이 됨
		if(input == a[mid]) break;
		else if(input > a[mid]) first=mid+1;
		else if(input < a[mid]) last=mid-1;
	}
	
	printf("%d", mid+1);  // 몇 번째인지 물었으므로 index(==mid)+1 출력

	return 0;
}

