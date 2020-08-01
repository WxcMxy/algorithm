#include <stdio.h>
#include <stdlib.h>
#define INTMAX 999//定义正无穷 

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
	
	printf("请输入村庄的数目：");
	scanf("%d", &n);
	a = (int *)malloc(sizeof(int) * (n+1));
	
	InitGraph(n, &G);
	CreateGraph(&G);
	for(i=0;i<n+1;i++){
		for(j=0;j<n+1;j++){
			if(G.graph[i][j] == INTMAX)
				printf(" ∞");
			else 
				printf("%3d", G.graph[i][j]);
		}
		
		printf("\n");
	}
	
	
	for(i = 1; i < n+1; i++){
		a[i] = Dijskra(n, i, &G);
	}
	
	hos = FindMin_M(a, n);
	printf("选择%d号村庄作为医院最合适。", hos);
	
	return 0;
}

//初始化图 
void InitGraph(int n, struct Graph * G){
	int i,j;
	
	//动态分配内存
	G->graph = (int **) malloc(sizeof(int *) * (n+1));
	for(i = 0; i < n+1; i++)
		G->graph[i] = (int *)malloc(sizeof(int) * (n+1));
	G->path = (int *)malloc(sizeof(int) * (n+1));
	G->pre = (int *)malloc(sizeof(int) * (n+1));
	
	//初始化 
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
			G->graph[i][j] = INTMAX;//先把路径长都赋为正无穷 
	}
	
	return ;
}
//填充图 
void CreateGraph(struct Graph * G){
	int x, y, len;
	printf("请输入两点和它们之间的距离（x y len）,结束输入0：\n"); 
	do
	{
		scanf("%d %d %d", &x, &y, &len);
		G->graph[x][y] = G->graph[y][x] = len;	
	}while(x != 0); 
	
	return ; 
}
//求单源最短路径 
int Dijskra(int n, int vi, struct Graph * G){
	int vj, k, i, sum = 0;
	int * s;
	G->path[vi] = 0;
	
	//定义一个数组，记录顶点是否被选中 
	s = (int *)malloc(sizeof(int) * (n+1));
	for(k = 0; k < n+1; k++)
		s[k] = 0;
	
	//将与源点有路径的顶点记录上 
	for(k = 1; k < n+1; k++){
		G->path[k] = G->graph[vi][k];
		if(G->graph[vi][k] != INTMAX)
			G->pre[k] = vi;
	}
	s[vi] = 1;
	
	//找寻源点与其他顶点之间的最短路径 
	for(i = 1; i < n; i++){ 
	
		//找与源点直接或间接联系的顶点的最小路径 ，并纳入图中
		vj = FindMin_D(G, n, s); 
		s[vj] = 1;
		
		//找寻因新纳入顶点而联系到的其他的顶点，并作必要的路径更新 
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
 
