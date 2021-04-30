#include <stdio.h>
using namespace std;

int main(){
	int i=1, cNum=0, hNum=0, result;
	char a[9] = "";
	scanf("%s", &a);
	
	/* cNum(탄소의 갯수) */
	// C(탄소)의 질량이 표시되지 않았을 경우
	if(a[1]=='H'){
		cNum=1;
		i+=1;
	}
	// 표시됐을 경우 
	else{
		while(a[i] != 'H'){
			cNum += a[i]-48;
			if(a[i+1] != 'H'){
				cNum*=10;
				i++;
			} else {
				i+=2;
				break;
			}
		}
	}
	
	/* hNum(수소의 갯수) */
	// H(수소)의 질량이 표시되지 않았을 경우
	if(a[i]=='\0') hNum=1;
	// 표시됐을 경우
	else{
		while(a[i]!='\0'){
			hNum += a[i]-48;
			if(a[i+1]!='\0'){
				hNum*=10;
				i++;
			}
			else break;
		}
	}
	
	result = 12*cNum + 1*hNum;
	printf("%d", result);

	return 0;
}

