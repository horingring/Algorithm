#include <stdio.h>
using namespace std;

int main(){
	int n, temp;
	scanf("%d", &n);
	int ch[n+1]={0,};
	
	for(int i=2; i<=n; i++){
		temp=i;
		int j=2;
		while(1){
			if(temp%j == 0){
				temp = temp/j;
				ch[j]++;
			} else {
				j++;
			}
			if(temp==1) break;
		}
	}
	
	printf("%d! = ", n);
	for(int i=2; i<=n; i++){
		if(ch[i]!=0){
			printf("%d ", ch[i]);	
		}
		
	}

	return 0;
}

