#include <stdio.h>
using namespace std;

int main(){
	int n, check=0, temp, digit;
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++){
		temp = i;
		for(int j=0; temp>=1; j++){
			digit = temp%10;
			if(digit==3) check++;
			temp=temp/10;
		}
	}
	
	printf("%d", check);

	return 0;
}

