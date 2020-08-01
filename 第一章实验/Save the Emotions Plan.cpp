#include <stdio.h>
#include <stdlib.h>
#define N 50001

//输入函数 
int shuru(int n,int a[])
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("\n请输入该堆的第%d个数的数值：",i);
		scanf("%d",&a[i]);
	}
	return 0;
}

//拯救计划，寻找是否有和为10000的两值 
int zhengjiujihua(int a[],int b[],int n,int x)
{
	if(a[n]+b[x]==10000)                            //找到和为10000的两个数后，返回1 
	return 1;                                 
	else if(a[n]+b[x]!=100&&n!=1&&x!=1)             //从两数列尾部开始找，一数列先固定于尾部，另一数列从后往前找 
	 zhengjiujihua(a,b,n,x-1);                     
	else if(a[n]+b[x]!=100&&n!=1&&x==1)              //当第二堆数列找到第一位时，第一堆数列向前找以为，第二堆数列继续回到尾部，从后往前找 
	{
		x=b[0];
		zhengjiujihua(a,b,n-1,x);
	}
	else                                             //直到两数列都找到第一个数，仍然没有和为10000时返回0 
	 return 0;
} 
 
int main()
{
	int a[N],b[N],result,n,x;
	printf("输入第一堆的数据个数：");
	scanf("%d",&n);
	a[0]=n;
	shuru(n,a);
	printf("\n输入第二堆数据个数：");
	scanf(" %d",&x);
	b[0]=x;
	shuru(x,b);
	result=zhengjiujihua(a,b,n,x);
	if(result==1)                                  //该判断用于将函数返回的数值转换为文字输出 
	printf("YES!");
	else
	printf("NO!");
	return 0;
	
	
}
