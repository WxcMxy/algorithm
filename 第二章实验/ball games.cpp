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
	printf("����������������");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("�������%d�������Ŀ�ʼʱ��ͽ���ʱ�䣨�磺0 2����",i+1);
		scanf("%d %d",&a[i],&b[i]); 
	}
	s=GreedySelector(n,a,b,A);
	printf("�ɿ�������Ϊ%d",s);
	return 0;
}
