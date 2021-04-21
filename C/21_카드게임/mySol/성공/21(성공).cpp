#include <stdio.h>
using namespace std;

int main(){
	int sub, scoreA=0, scoreB=0;
	char joker='D';
	int a[10], b[10];
	
	for(int i=0; i<10; i++){
		scanf("%d", &a[i]);
	}
	for(int i=0; i<10; i++){
		scanf("%d", &b[i]);
	}
	
	for(int i=0; i<10; i++){
		sub = a[i] - b[i];
		if(sub > 0) {
			scoreA+=3;
			joker = 'A';
		} else if(sub < 0){
			scoreB+=3;
			joker = 'B';
		} else if(sub == 0) {
			scoreA++;
			scoreB++;
		}
	}
	
	printf("%d %d\n", scoreA, scoreB);
	
	if(scoreA > scoreB) printf("A");
	else if(scoreB > scoreA) printf("B");
	else if(scoreA == scoreB){
		if(joker == 'A') printf("%c", joker);
		else if(joker == 'B') printf("%c", joker);
		else if(joker == 'D') printf("%c", joker);
	}
	
	
	return 0;
}

