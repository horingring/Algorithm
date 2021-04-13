#include <iostream>

int main() {
	int N, i, current, max=0, min=1000000, sub=0;
	std::cin>>N;
	for(i=1; i<=N; i++){
		std::cin>>current;
		if(min>=current){
			min = current;
		}
		if(max<=current){
			max = current;
		}
	}
	sub = max - min;
	std::cout<<sub;
	
	return 0;
}
