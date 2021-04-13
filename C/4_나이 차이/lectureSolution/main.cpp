#include <iostream>
using namespace std;

int main() {
//	freopen("input.txt", "rt", stdin);
	int N, i, current, max=-2147000000, min=2147000000, sub=0;
	cin>>N;
	for(i=1; i<=N; i++){
		cin>>current;
		if(min>=current)	min = current;
		
		if(max<=current)	max = current;
	}
	sub = max - min;
	cout<<sub;
	
	return 0;
}
