#include <stdio.h>
#include <stdlib.h>
#define INTMAX 999//���������� 

struct Graph{
	int ** graph;
	int * path;
	int * pre;
};

void InitGraph(int n, struct Graph * G);
void CreateGraph(struct Graph * G);
int Dijskra(int n, int vi, struct Graph * G);
int FindMin_D(struct Graph * G, int n, int * s);
int FindMin_M(int * a, int n);

int main(){
	int n, i, j, hos;
	int * a;
	struct Graph G;
	
	printf("�������ׯ����Ŀ��");
	scanf("%d", &n);
	a = (int *)malloc(sizeof(int) * (n+1));
	
	InitGraph(n, &G);
	CreateGraph(&G);
	for(i=0;i<n+1;i++){
		for(j=0;j<n+1;j++){
			if(G.graph[i][j] == INTMAX)
				printf(" ��");
			else 
				printf("%3d", G.graph[i][j]);
		}
		
		printf("\n");
	}
	
	
	for(i = 1; i < n+1; i++){
		a[i] = Dijskra(n, i, &G);
	}
	
	hos = FindMin_M(a, n);
	printf("ѡ��%d�Ŵ�ׯ��ΪҽԺ����ʡ�", hos);
	
	return 0;
}

//��ʼ��ͼ 
void InitGraph(int n, struct Graph * G){
	int i,j;
	
	//��̬�����ڴ�
	G->graph = (int **) malloc(sizeof(int *) * (n+1));
	for(i = 0; i < n+1; i++)
		G->graph[i] = (int *)malloc(sizeof(int) * (n+1));
	G->path = (int *)malloc(sizeof(int) * (n+1));
	G->pre = (int *)malloc(sizeof(int) * (n+1));
	
	//��ʼ�� 
	G->graph[0][0] = G->path[0] = G->pre[0] = 0;
	for(i = 1; i < n+1; i++)
	{
		G->graph[0][i] = i;
		G->graph[i][0] = i;
		G->path[i] = INTMAX;
		G->pre[i] = 0;
	}
	for(i = 1; i < n+1; i++)
	{
		for(j = 1; j < n+1; j++)
			G->graph[i][j] = INTMAX;//�Ȱ�·��������Ϊ������ 
	}
	
	return ;
}
//���ͼ 
void CreateGraph(struct Graph * G){
	int x, y, len;
	printf("���������������֮��ľ��루x y len��,��������0��\n"); 
	do
	{
		scanf("%d %d %d", &x, &y, &len);
		G->graph[x][y] = G->graph[y][x] = len;	
	}while(x != 0); 
	
	return ; 
}
//��Դ���·�� 
int Dijskra(int n, int vi, struct Graph * G){
	int vj, k, i, sum = 0;
	int * s;
	G->path[vi] = 0;
	
	//����һ�����飬��¼�����Ƿ�ѡ�� 
	s = (int *)malloc(sizeof(int) * (n+1));
	for(k = 0; k < n+1; k++)
		s[k] = 0;
	
	//����Դ����·���Ķ����¼�� 
	for(k = 1; k < n+1; k++){
		G->path[k] = G->graph[vi][k];
		if(G->graph[vi][k] != INTMAX)
			G->pre[k] = vi;
	}
	s[vi] = 1;
	
	//��ѰԴ������������֮������·�� 
	for(i = 1; i < n; i++){ 
	
		//����Դ��ֱ�ӻ�����ϵ�Ķ������С·�� ��������ͼ��
		vj = FindMin_D(G, n, s); 
		s[vj] = 1;
		
		//��Ѱ�������붥�����ϵ���������Ķ��㣬������Ҫ��·������ 
		for(k = 1; k < n+1; k++){
			if((G->graph[vj][k] != INTMAX) && (s[k] == 0) && (G->path[k] > (G->graph[vj][k] + G->path[vj]))){
				G->path[k] = G->graph[vj][k] + G->path[vj];
				G->pre[k] = vj;}
		}
		sum = sum + G->path[vj];
	}
	
	return sum;
}

int FindMin_D(struct Graph *G, int n, int * s){
	int i, p = 1, temp = G->path[1];
	for(i = 2; i < n+1; i++){
		if((s[i] == 0) && (temp > G->path[i]))
			p = i; 
	}
	
	return p;
}

int FindMin_M(int * a, int n){
	int i, p, temp = a[0];
	for(i = 1; i < n; i++){
		if(temp > a[i])
			p = 1;
	}
	
	return p;
}
 
