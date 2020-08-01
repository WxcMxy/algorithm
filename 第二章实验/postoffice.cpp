#include<stdio.h>
#define MAX 101
int Post_office(int P[],int H[],int n){
    P[1]=H[1]+1000;  
	int i,m=1;
	for(i=2;i<=n;i++){
        if(H[i]>P[m]+1000){
            m++;
			P[m]=H[i]+1000;
		}
	}
	if(P[m]>H[n])
	    P[m]=H[n]; 
	return m;
}
int main()
{
    int P[MAX];
	int H[MAX];
	int n=0;
	int m=0;
	printf("请输入共有人家数n:\n");
	scanf("%d",&n);
	printf("请输入每户人家距村西头的距离:\n");
	for(int i=1;i<=n;i++){
        scanf("%d",&H[i]);
	}
	m=Post_office(P,H,n);
    printf("这一共有%d个邮局\n",m);
	for(int i=1;i<=m;i++){
	    printf("第%d个邮局到街西头的距离：%d\n",i,P[i]);
	}
	return 0; 
}

