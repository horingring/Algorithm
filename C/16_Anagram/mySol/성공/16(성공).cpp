#include <stdio.h>
using namespace std;

int main(){
	char a[101];
	int n=0;
	scanf("%s", &a);
	for(int i=0; a[i]!='\0'; i++){
		n++;
	}
	
	int b[n+2][2] = {0,};
	for(int i=0; a[i]!='\0'; i++){
		for(int j=0; j<n; j++){
			if(b[j][0]==0){
				b[j][0] = a[i];
				b[j][1]++;
				break;
			}
			else if(a[i]!=b[j][0]) continue;
			else if(a[i]==b[j][0]){
				b[j][1]++;
				break;	
			} 
		}
	}
	
	for(int i=0; i<n+2; i++){
		if(b[i][0]==0) {
			if(b[i-1][0]=='!'){
				b[i][0]='\0';		
			}else{
				b[i][0]='!';
			}
		}
	}
	
	char c[101];
	scanf("%s", &c);
	for(int i=0; c[i]!='\0'; i++){
		for(int j=0; b[j][0]!='\0'; j++){
			if(c[i]==b[j][0]){
				b[j][1]--;
				break;
			}else if(c[i]!=b[j][0]) continue;
			else if(b[j][0]=='!'){
				printf("%s", "NO");
				return 0;
			}
		}
	}
	
	for(int i=0; i<n; i++){
		if(b[i][1]!=0){
			printf("%s", "NO");
			return 0;
		}else if(b[i][1]==0){
			continue;
		}
	}
	
	printf("%s", "YES");
	
	return 0;
}

