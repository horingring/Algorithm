#include <stdio.h>
using namespace std;

int main(){
	char a[101];
	int b[10]={0,};
	int i, currentNum, maxCnt=-1, maxNum=9;
	
	scanf("%s", &a);
	
	for(i=0; a[i]!='\0'; i++){
		currentNum = a[i]-48;
		b[currentNum]++;
		
		if(maxCnt < b[currentNum]){
			maxCnt = b[currentNum];
			maxNum = currentNum;
		}else if(maxCnt == b[currentNum]){
			if(maxNum < currentNum) maxNum = currentNum;
		}
	}
	
	printf("%d", maxNum);
	
	
	return 0;
}

