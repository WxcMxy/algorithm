#include <stdio.h>
#include <stdlib.h>
#define N 50001

//���뺯�� 
int shuru(int n,int a[])
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("\n������öѵĵ�%d��������ֵ��",i);
		scanf("%d",&a[i]);
	}
	return 0;
}

//���ȼƻ���Ѱ���Ƿ��к�Ϊ10000����ֵ 
int zhengjiujihua(int a[],int b[],int n,int x)
{
	if(a[n]+b[x]==10000)                            //�ҵ���Ϊ10000���������󣬷���1 
	return 1;                                 
	else if(a[n]+b[x]!=100&&n!=1&&x!=1)             //��������β����ʼ�ң�һ�����ȹ̶���β������һ���дӺ���ǰ�� 
	 zhengjiujihua(a,b,n,x-1);                     
	else if(a[n]+b[x]!=100&&n!=1&&x==1)              //���ڶ��������ҵ���һλʱ����һ��������ǰ����Ϊ���ڶ������м����ص�β�����Ӻ���ǰ�� 
	{
		x=b[0];
		zhengjiujihua(a,b,n-1,x);
	}
	else                                             //ֱ�������ж��ҵ���һ��������Ȼû�к�Ϊ10000ʱ����0 
	 return 0;
} 
 
int main()
{
	int a[N],b[N],result,n,x;
	printf("�����һ�ѵ����ݸ�����");
	scanf("%d",&n);
	a[0]=n;
	shuru(n,a);
	printf("\n����ڶ������ݸ�����");
	scanf(" %d",&x);
	b[0]=x;
	shuru(x,b);
	result=zhengjiujihua(a,b,n,x);
	if(result==1)                                  //���ж����ڽ��������ص���ֵת��Ϊ������� 
	printf("YES!");
	else
	printf("NO!");
	return 0;
	
	
}
