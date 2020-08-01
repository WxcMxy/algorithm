#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
 
	int a[1000],n;
	scanf("%d",&n);
	int i,sum=0;
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
		for(i=0;i<n;i++){
			sum=sum+(a[i]*(n-1-i));
		}
	printf("%d\n",sum/n);
} 
