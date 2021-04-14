#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main(){
	char a[31];
	int i, j, start=0, end=0;
	string result="";
	
	scanf("%s", a);
	
	for(j=0; a[j]!='\0'; j++){
		j++;
	}
	
	if(a[0]==')' || a[j-1]=='('){
		result="NO";
		cout<<result;
		return 0;
	}
	
	for(i=0; a[i]!='\0'; i++){
		if(a[i]=='(') start++;
		else end++;
	}
	
	if(start==end) result="YES";
	else result="NO";
	
//	printf("%s", result);
	cout<<result;
	
	return 0;
}

