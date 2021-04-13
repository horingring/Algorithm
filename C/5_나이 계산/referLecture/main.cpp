#include <stdio.h>
#include <stdlib.h>
#include <string>

int main() {
//	freopen("input.txt", "rt", stdin);
	char a[15];
	int age, currentYear=2019, birthYear;
	char sex;
	scanf("%s", &a);
	if(a[7]=='1'||a[7]=='2'){
		birthYear = 1900 + (a[0]-48)*10+(a[1]-48);
		age = currentYear - birthYear + 1;
	}
	else if(a[7]=='3'||a[7]=='4'){
		birthYear = 2000 + (a[0]-48)*10+(a[1]-48);
		age = currentYear - birthYear + 1;
	}
	
	if(a[7]=='1'||a[7]=='3') sex='M';
	else if(a[7]=='2'||a[7]=='4') sex='W';
	
	printf("%d %c", age, sex);
	
	
	return 0;
}
