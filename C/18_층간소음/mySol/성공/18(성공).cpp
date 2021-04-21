#include <stdio.h>
using namespace std;

int main(){
	int n, m, sound, stack=0, max=-1;
	
	scanf("%d %d", &n, &m);
	
	for(int i=0; i<n; i++){
		scanf("%d", &sound);
		if(sound > m){
			stack++;
			if(max < stack) max=stack;
		} else stack=0;
	}
	if(max==0) max=-1;	
	printf("%d", max);
	return 0;
}

