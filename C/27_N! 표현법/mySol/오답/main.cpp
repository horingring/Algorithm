#include <stdio.h>
using namespace std;

int main(){
	int n, k=0;
	scanf("%d", &n);
	printf("%d! = ", n);
	
	//소수를 구해서 b 배열에 넣는 로직
	int a[n+2]={0,};

	for(int i=2; i<=n; i++){
		a[i] = 1;
	}
	
	int b[n]={0,};
	
	a[0]=0;
	a[1]=0;
	b[0]=2;
	k++;
	
	for(int i=3; i<=n; i+=2){
		if(a[i] == 1){
			b[k] = i;
			k++;
			for(int j=2; i*j<=n; j++){
				a[i*j]=0;
			}
		}
	}
	
//	for(int i=0; i<n; i++){
//		printf("%d ", b[i]);
//	}


	// num (==n!)을 b의 소수로 차례대로 나누는 로직
	int num = 1, cnt=0;
	for(int i=1; i<=n; i++){
		num *= i;
	}
	
	for(int i=0; b[i]!='\0'; i++){
		cnt = 0;
		while(num%b[i]==0){
			num = num/b[i];
			cnt++;
		}
		if(num==1){
			printf("%d", cnt);
			break;
		}
		printf("%d ", cnt);
	}

	return 0;
}

