#include<stdio.h>
#include<stdlib.h>
int board[102][102];
int tile=1;
int chessBoard(int tr,int tc,int dr,int dc,int size)
{	
    if (size == 1) return 0;
    int t = tile++; // L型骨牌号
    int  s = size/2; // 分割棋盘
    // 覆盖左上角子棋盘
    if (dr < tr + s && dc < tc + s)
    // 特殊方格在此棋盘中
    chessBoard(tr, tc, dr, dc, s);
    else {// 此棋盘中无特殊方格
    // 用 t 号L型骨牌覆盖右下角
    board[tr + s - 1][tc + s - 1] = t;
    // 覆盖其余方格
    chessBoard(tr, tc, tr+s-1, tc+s-1, s);}
    // 覆盖右上角子棋盘
    if (dr < tr + s && dc >= tc + s)
    // 特殊方格在此棋盘中
   chessBoard(tr, tc+s, dr, dc, s);
    else {// 此棋盘中无特殊方格
    // 用 t 号L型骨牌覆盖左下角
    board[tr + s - 1][tc + s] = t;
    // 覆盖其余方格
    chessBoard(tr,tc+s,tr+s-1,tc+s, s);}
    if (dr >= tr + s && dc < tc + s)
    // 特殊方格在此棋盘中
    chessBoard(tr+s, tc, dr, dc, s);
    else {// 用 t 号L型骨牌覆盖右上角
    board[tr + s][tc + s - 1] = t;
    // 覆盖其余方格
    chessBoard(tr+s, tc, tr+s, tc+s-1, s);}
    // 覆盖右下角子棋盘
    if (dr >= tr + s && dc >= tc + s)
    // 特殊方格在此棋盘中
    chessBoard(tr+s, tc+s, dr, dc, s);
    else {// 用 t 号L型骨牌覆盖左上角
    board[tr + s][tc + s] = t;
    // 覆盖其余方格
    chessBoard(tr+s, tc+s, tr+s, tc+s, s);}
}
int main()
{
    int n,x,y,size,i,j;
    scanf("%d%d%d",&n,&x,&y);
    size=1; 
    while(n)
    { 
         n--;
         size*=2;
    }
    chessBoard(0,0,x-1,y-1,size);
       
    for(i=0;i<size;i++)
    {
        for (j=0;j<size;j++)
           printf("%3d ",board[i][j]);
        printf("\n");
    }
    system("pause");
}
