#include <stdio.h>
using namespace std;

int main(){
	int n, m, iA=0, iB=0, iC=0, p1, p2;
	int min, minIndex, temp;
	scanf("%d", &n);
	int a[n]={0,};
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	for(int i=0; i<n-1; i++){
		min=a[i];
		minIndex=i;
		for(int j=i+1; j<n; j++){
			if(min>a[j]){
				min=a[j];
				minIndex=j;
			}
		}
		if(min!=a[i]){
			temp=a[i];
			a[i]=min;
			a[minIndex]=temp;
		}
	}
	
	scanf("%d", &m);
	int b[m]={0,};
	for(int i=0; i<m; i++){
		scanf("%d", &b[i]);
	}
	
	for(int i=0; i<m-1; i++){
		min=b[i];
		minIndex=i;
		for(int j=i+1; j<m; j++){
			if(min>b[j]){
				min=b[j];
				minIndex=j;
			}
		}
		if(min!=b[i]){
			temp=b[i];
			b[i]=min;
			b[minIndex]=temp;
		}
	}
	
	int c[n+m] = {0,};
	for(int i=0; i<n+m; i++){
		c[i] = -2147000000;
	}
	
	
	p1=a[iA];  // p1=a[0]
	p2=b[iB];  // p2=b[0]
	
	while(iA <= n && iB <= m){
		if(p1==p2){
			c[iC++]=p1;
			p1 = a[++iA];
			p2 = b[++iB];
		} else if(p1<p2){
			p1 = a[++iA];
		} else if(p1>p2){
			p2 = b[++iB];
		} 
	}
	
	
	for(int i=0; c[i]!=-2147000000; i++){
		printf("%d ", c[i]);	
	}

	return 0;
}

