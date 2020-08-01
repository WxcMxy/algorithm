#include<stdio.h>
void MergeSort(int a[],int s,int e,int temp[]);
void Merge(int a[],int s,int m,int e,int temp[]);

void MergeSort(int a[],int s,int e,int temp[])
{
	if(s<e)
	{
		int m = s+(e-s)/2;
		MergeSort(a,s,m,temp);
		MergeSort(a,m + 1,e,temp);
		Merge(a,s,m,e,temp);
	}
	
}

void Merge(int a[],int s,int m,int e,int temp[])
{
	int pb = 0;
	int p1 = s,p2 = m + 1;
	while(p1<= m&&p2<= e)
	{
		if(a[p1] < a[p2])
			temp[pb++] = a[p1++];
		else
			temp[pb++] = a[p2++];
	}
	while(p1<=m)
		temp[pb++] = a[p1++];
	while(p2<=e)
		temp[pb++] = a[p2++];
	for(int i = 0;i < e - s + 1;i++)
		a[s+i] = temp[i];
}


int main()
{  
 	int total = 0;
	int n;
	printf("请输入有几堆果子"); 
	scanf("%d\n",&n);
	int wi[n];
	int temp[n];
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&wi[i]);
	}
	MergeSort(wi,0,n - 1,temp);
	while(n > 1)
	{
		total += (wi[0] + wi[1]);
		wi[0] += wi[1];
		for(int i = 1;i < n - 1;i++)
			wi[i] = wi[i + 1];
		     n--;
		for(int i = 0;i < n - 1;i++)
		{
			if(wi[i] > wi[i + 1])
			{						
				int temp = wi[i];
				wi[i] = wi[i + 1];
				wi[i + 1] = temp;
			}
			
		}
	}

	printf("最小花费的体力值是%d",total);//输出结果 
	return 0;
}
