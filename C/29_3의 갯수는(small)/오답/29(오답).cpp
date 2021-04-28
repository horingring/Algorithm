#include <stdio.h>
using namespace std;

int main(){
	int n, check=0, temp;
	scanf("%d", &n);
	int a[7] = {0,};
	
	for(int i=1; i<=n; i++){
		temp = i;
		for(int j=0; temp>=1; j++){
			a[j] = temp%10;
			temp=temp/10;
			if(temp<1){
				// 오답의 이유: '\0'
				a[j+1]='\0';
			}
		}

		// 오답의 이유: '\0'	
		for(int j=0; a[j]!='\0'; j++){
			if(a[j]==3) check++;
		}
		
		for(int j=0; j<7; j++){
			a[j] = 0;
		}
	}
	
	printf("%d", check);

	return 0;
}

