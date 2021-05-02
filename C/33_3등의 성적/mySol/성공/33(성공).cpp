#include <stdio.h>
using namespace std;

int main(){
	int n, temp, cnt=0, grade=0;
	scanf("%d", &n);
	int a[n];
	
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	for(int i=0; i<n-1; i++){
		//똑같은 수일 경우 continue
		if(cnt!=0){
			cnt--;
			continue;
		}

		//내림차순 정렬
		for(int j=i+1; j<n; j++){
			if(a[i]<a[j]){
				temp = a[i];
				a[i]=a[j];
				a[j]=temp;
			}

			/* 똑같은 수가 있을 경우 */
			// i 인덱스의 다음, 다다음...에 해당 수를 위치시켜 준다.
			if(a[i]==a[j]){
				cnt++;
				temp = a[i+cnt];
				a[i+cnt] = a[j];
				a[j]=temp;
			}
		}
		//하나의 고유한 수가 내림차순 정렬되면, grade++ (1등 -> 2등 -> 3등 ...)
		grade++;
		//3등이면 출력
		if(grade==3){
			printf("%d", a[i]);	
			break;
		} 
	}

	return 0;
}

