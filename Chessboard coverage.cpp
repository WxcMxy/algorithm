#include <stdio.h>
#include <stdlib.h>

void chessBoard(int tr,int tc,int size,int dr,int dc){
	if(size==1)
	return; 
    if(size==2){
        if(dr==tr&&dc==tc)
		printf("%d %d %d\n",tr+1,tc+1,1);
        if(dr==tr&&dc==tc+1)
		printf("%d %d %d\n",tr+1,tc,2);
        if(dr==tr+1&&dc==tc)
		printf("%d %d %d\n",tr,tc+1,3);
        if(dr==tr+1&&dc==tc+1)
		printf("%d %d %d\n",tr,tc,4);
        return; 
    };
    int s=size/2; 
    if(dr<tr+s&&dc<tc+s){
        chessBoard(tr,tc,s,dr,dc);
        printf("%d %d %d\n",tr+s,tc+s,1);
    }
    else 
	chessBoard(tr,tc,s,tr+s-1,tc+s-1); 
    
    
    if(dr<tr+s&&dc>=tc+s){
        chessBoard(tr,tc+s,s,dr,dc);
        printf("%d %d %d\n",tr+s,tc+s-1,2);
    }
    else 
	chessBoard(tr,tc+s,s,tr+s-1,tc+s);
 
   
    if(dr>=tr+s&&dc<tc+s){
        chessBoard(tr+s,tc,s,dr,dc);
        printf("%d %d %d\n",tr+s-1,tc+s,3);
    }
    else 
	chessBoard(tr+s,tc,s,tr+s,tc+s-1);
 
 
    if(dr>=tr+s&&dc>=tc+s){
        chessBoard(tr+s,tc+s,s,dr,dc);
        printf("%d %d %d\n",tr+s-1,tc+s-1,4);
    }
    else 
	chessBoard(tr+s,tc+s,s,tr+s,tc+s);
}
main(){
    int k,x,y,size=1;
    printf("请输入k，即给定被填补迷宫的大小为 2k×2k\n");
    scanf("%d",&k);
    printf("x,yx,y，即给出公主所在方格的坐标（x 为行坐标，y为列坐标）\n");
     scanf("%d",&x);
      scanf("%d",&y);
    for(int i=1;i<=k;++i) 
	  size*=2;
     chessBoard(1,1,size,x,y);
} 
