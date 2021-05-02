#include <stdio.h>
using namespace std;

int main(){
	int n, k, temp;
	scanf("%d", &n);
	int a[n] = {0,};
	k = n;
	
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	for(int i=0; i<k-1; k--){
		for(int j=0; j<k-1; j++){
			//버블정렬 시
			//두 수 중 앞 수가 양수이면서, 뒷 수가 음수일 때만 
			//두 수의 위치를 교체
			if(a[j]>0 && a[j+1]<0){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}

	return 0;
}

