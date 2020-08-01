#include<stdio.h>
#define N 20
int GreedySelector(int n,int a[],int b[],bool A[])
{
	A[1]=true;
	int j=1,s=1;
	for(int i=2;i<n;i++)
	{
		if(a[i]>=b[j])
		{
			A[i]=true;
			j=i;
			s++;
		}
		else A[i]=false;
	}
	return s;
}
int main()
{
	int i,n,a[N],b[N],s;
	bool A[N]; 
	printf("请输入球赛场数：");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("请输入第%d场球赛的开始时间和结束时间（如：0 2）：",i+1);
		scanf("%d %d",&a[i],&b[i]); 
	}
	s=GreedySelector(n,a,b,A);
	printf("可看球赛数为%d",s);
	return 0;
}
