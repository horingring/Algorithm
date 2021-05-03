#include <stdio.h>
using namespace std;

int main(){
	int n, temp;
	scanf("%d", &n);
	int a[n]={0,};
	
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	//a[1] ~ a[n-1] 까지 다음의 삽입정렬을 반복
	for(int i=1; i<n; i++){
		//현재의 수(a[i])와 비교될 수(a[j])  // *이때 비교되는 수들은 삽입정렬에 의해 이미 정렬된 상태이다.
		for(int j=i-1; j>=0; j--){
			//현재의 수가 비교되는 수보다 크거나 같은 순간
			if(a[i]>=a[j]){
				temp = a[i];
				for(int k=i; k>j+1; k--){
					a[k]=a[k-1];
				}
				a[j+1]=temp;
				break;
			} else if(a[i]<a[j]){
				//현재의 수가 앞의 모든 수들보다 작을 경우(가장 작을 경우)
				if(j==0){
					temp = a[i];
					for(int k=i; k>=j+1; k--){  //for문의 조건문이 위와 다르다. ( k>=j+1 )
						a[k]=a[k-1];
					}
					a[j]=temp;	//마찬가지로 위와 다르다. 이번에는 a[0]의 수 역시 a[1]로 옮겨줘야 한다.
				}
			}
		}
	}
	
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}

	return 0;
}

