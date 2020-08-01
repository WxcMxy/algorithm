# include <stdio.h>
#define N 10

struct Student
{    
	char Major[10];
    char Sno[10];    
	char Name[20];    
	int Pnum;
};

void Sort (struct Student * pStu, int left, int right);
void Find(struct Student * pStu, int left, int right, int num, int count);

int main()
{    
	int n, i, num, count = 1;    
	struct Student stu[N];
	
    printf("请输入学生的人数：");    
	scanf("%d", &n);
	
    //录入学生的信息    
	for( i = 0; i < n; i++)       
		scanf("%s%s%s%d", stu[i].Major, stu[i].Sno, stu[i].Name, &(stu[i].Pnum));
	
	//输出未排序的学生名单
	printf("专业\t   学号\t      姓名\t 植树数\n");    
	for ( i = 0; i < n; i++ )        
		printf("%-10s %-10s %-10s %-d\n", stu[i].Major, stu[i].Sno, stu[i].Name, stu[i].Pnum);
		        
	//依据植树情况进行排序    
	Sort(stu, 0, n-1);
	
    //输出排好序的学生名单    
	printf("专业\t   学号\t      姓名\t 植树数\n");    
	for ( i = 0; i < n; i++ )        
		printf("%-10s %-10s %-10s %-d\n", stu[i].Major, stu[i].Sno, stu[i].Name, stu[i].Pnum);
		        
	//查找学生信息    
	printf("要查找的植树数目：");    
	scanf("%d", &num);    
	Find(stu, 0, n-1, num, count);   
	     
	return 0;
}
void Sort (struct Student * pStu, int left, int right)
{    
	int i, j, temp;    
	struct Student t, u;    
	if( left > right)        
		return ; //递归出口 
		       
	u = pStu[left];    
	temp = pStu[left].Pnum;    
	i = left;    
	j = right;    
	while ( i != j )    
	{        
		while ((pStu[j].Pnum >= temp) && (i <j))            
			j--;        
		while ((pStu[i].Pnum <= temp) && (i < j))            
			i++;        
		if (i < j)        
		{            
			t = pStu[i];            
			pStu[i] = pStu[j];            
			pStu[j] = t;        
		}    
	}
	
    pStu[left] = pStu[i];    
	pStu[i] = u;
	
    Sort(pStu, left, i-1);    
	Sort(pStu, i+1, right);
	
    return ;
}
void Find(struct Student * pStu, int left, int right, int num, int count)
{    
	int mid;    
	mid = (left + right)/2;
	
    if( pStu[mid].Pnum == num )    
	{        
		printf("该生排名在第%d位，查找%d次成功\n", mid + 1, count);        
		printf("%s %s %s %d\n", pStu[mid].Major, pStu[mid].Sno, pStu[mid].Name, pStu[mid].Pnum);    
	}    
	else    
	{        
		count++;        
		if( pStu[mid].Pnum > num)            
			Find(pStu, left, mid-1, num, count);        
		else            
			Find(pStu, mid+1, right, num, count);    
	}
	
    return ;    
}

