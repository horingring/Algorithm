#include <stdio.h>
using namespace std;

int main(){
	int n, card, sum, answer;
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &card);
		sum = 0;
		for(int j=1; j<=card; j++){
			sum += j;
		}
		
		scanf("%d", &answer);
		if(answer == sum){
			printf("%s", "YES\n");
		}else printf("%s", "NO\n");
	}
	
	return 0;
}

