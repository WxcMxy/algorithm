#include<stdio.h>
main()
{
	int n,i,j,x,y,s;
	char a[1000][1000];
	for(int x=0;x<1000;x++)
    {
        for(int y=0;y<1000;y++)
        {
            a[x][y] = ' ';
        }
    }
    a[0][1]=a[1][0]='/';
	a[0][2]=a[1][3]='\\';
	a[1][1]=a[1][2]='_';
	printf("ÇëÊäÈënµÄÖµ");
	scanf("%d",&n);
for(s=2;s<n+1;s++)
{	int row=1,col=1;
	for(i=0;i<s;i++)
	{
	row*=2;
	}
	for(i=0;i<s+1;i++)
	{
	col*=2;
	}
	for(i=row/2;i<row;i++)
	{	
		for(j=0;j<col/2;j++)
		{
		a[i][j]=a[i-row/2][j]; 
		}
	}
	for(i=row/2;i<row;i++)
	{
		for(j=col/2;j<col;j++)
		{
		a[i][j]=a[i-row/2][j-row]; 
		}
	}
	for(int x=0;x<row/2;x++)
    {
        for(int y=0;y<col/2;y++)
        {
            a[x][y] = ' ';
        }
    }
	for(i=0;i<row/2;i++)
	{	
		for(j=row/2;j<3*row/2;j++)
		{
		a[i][j]=a[i+row/2][j-row/2]; 
		}
	}
}
	int row=1,col=1;
	for(i=0;i<n;i++)
	{
	row*=2;
	}
	for(i=0;i<n+1;i++)
	{
	col*=2;
	}
	for (x=0; x<row; x++)
    {
        for (y=0; y<col; y++)
        {
            printf("%c", a[x][y]);
        }
        printf("\n");
    }
printf("%c", a[x][y]);
	}    
