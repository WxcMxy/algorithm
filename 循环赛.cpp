#include<iostream>
#include<iomanip> //ͷ�ļ� 
using namespace std; //���еı�׼�⺯�����ڱ�׼�����ռ�std�н����˶��塣���ⷢ��������������
void Table(int n,int N,int k,int a[100][100])
{
	for(int i=1;i<=N;i++) a[1][i]=i;//һ�ź�ʣ���˵ı��� 
	int m=1;//��С��ģ�������� 
	for(int s=1;s<=k;s++)
	{
		N/=2;//���� 
		for(int t=1;t<=N;t++)//ȡֵʱ��Ҫ����� 
		{
			for(int i=m+1;i<=2*m;i++)
			    for(int j=m+1;j<=2*m;j++)
			    {
			    	a[i][j+(t-1)*m*2]=a[i-m][j+(t-1)*m*2-m];//���Ͻ�����½� ���½�����Ͻ� 
			    	a[i][j+(t-1)*m*2-m]=a[i-m][j+(t-1)*m*2];
				}
	    }
		m*=2;//������2���������� 
	}
}
void print(int n,int a[100][100])
{
	printf("ѭ�����ճ̱�\n");  
	cout<<"����:";//cout<<"Ҫ���������"
	for(int p=1;p<n;p++)  cout<<setw(4)<<setfill('-')<<p;//setw()���������� setfill������ַ��� oimanip�� 
	cout<<endl;//�����������
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
	printf("������k:\n");
	scanf("%ld",&k);
	for(int i=1;i<=k;i++) {
			n*=2;//n=2^k;
	}
	cout<<"��������:"<<n<<endl;
	int N=n;
	Table(n,N,k,a);
	print(n,a);
}
