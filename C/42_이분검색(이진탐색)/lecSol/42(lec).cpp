#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, input, first, last, mid, tmp;
	scanf("%d %d", &n, &input);
	vector<int> a;	// a의 크기를 할당하지 않음
	
	for(int i=0; i<n; i++){
		scanf("%d", &tmp);
		a.push_back(tmp);	// vector의 push_back 메서드는 인자를 vector 배열에 넣어주고 크기를 동적할당 함
	}
	
	sort(a.begin(), a.end()); //a.begin()는 vector a의 첫 주소를 가리키고, a.end()는 a의 마지막 index+1를 가리킨다.
	
	first = 0;
	last = n-1;
	
	while(first <= last){	// <----- 42(ref).cpp 에서는 true로 설정했었음.. 하지만 그렇게 하면 원하는 수를 찾지 못할 경우 무한루프를 돌게 됨
		mid = (first+last)/2;
		if(input == a[mid]) break;
		else if(input > a[mid]) first=mid+1;
		else if(input < a[mid]) last=mid-1;
	}
	
	printf("%d", mid+1);

	return 0;
}

