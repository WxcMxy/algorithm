#include<iostream>
#include<iomanip> //头文件 
using namespace std; //所有的标准库函数都在标准命名空间std中进行了定义。避免发生重命名的问题
void Table(int n,int N,int k,int a[100][100])
{
	for(int i=1;i<=N;i++) a[1][i]=i;//一号和剩余人的比赛 
	int m=1;//最小规模的子问题 
	for(int s=1;s<=k;s++)
	{
		N/=2;//划分 
		for(int t=1;t<=N;t++)//取值时需要填几部分 
		{
			for(int i=m+1;i<=2*m;i++)
			    for(int j=m+1;j<=2*m;j++)
			    {
			    	a[i][j+(t-1)*m*2]=a[i-m][j+(t-1)*m*2-m];//左上角填到右下角 右下角填到左上角 
			    	a[i][j+(t-1)*m*2-m]=a[i-m][j+(t-1)*m*2];
				}
	    }
		m*=2;//步长以2的幂在增长 
	}
}
void print(int n,int a[100][100])
{
	printf("循环赛日程表\n");  
	cout<<"日期:";//cout<<"要输出的内容"
	for(int p=1;p<n;p++)  cout<<setw(4)<<setfill('-')<<p;//setw()控制输出间隔 setfill（填充字符） oimanip中 
	cout<<endl;//程序输出结束
	for(int i=1;i<=n;i++)
	{
		cout<<setw(3)<<setfill('-')<<a[i][1]<<"|";
		for(int j=2;j<=n;j++)
		cout<<setw(4)<<setfill(' ')<<a[i][j];
		cout<<endl;
	} 
}
int main()
{
	int k;
	int a[100][100];
	int n=1;
	printf("请输入k:\n");
	scanf("%ld",&k);
	for(int i=1;i<=k;i++) {
			n*=2;//n=2^k;
	}
	cout<<"参赛人数:"<<n<<endl;
	int N=n;
	Table(n,N,k,a);
	print(n,a);
}
