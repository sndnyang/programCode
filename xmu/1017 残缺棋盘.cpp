#include<stdio.h>
#include<stdlib.h>
int board[102][102];
int tile=1;
int chessBoard(int tr,int tc,int dr,int dc,int size)
{	
    if (size == 1) return 0;
    int t = tile++; // L�͹��ƺ�
    int  s = size/2; // �ָ�����
    // �������Ͻ�������
    if (dr < tr + s && dc < tc + s)
    // ���ⷽ���ڴ�������
    chessBoard(tr, tc, dr, dc, s);
    else {// �������������ⷽ��
    // �� t ��L�͹��Ƹ������½�
    board[tr + s - 1][tc + s - 1] = t;
    // �������෽��
    chessBoard(tr, tc, tr+s-1, tc+s-1, s);}
    // �������Ͻ�������
    if (dr < tr + s && dc >= tc + s)
    // ���ⷽ���ڴ�������
   chessBoard(tr, tc+s, dr, dc, s);
    else {// �������������ⷽ��
    // �� t ��L�͹��Ƹ������½�
    board[tr + s - 1][tc + s] = t;
    // �������෽��
    chessBoard(tr,tc+s,tr+s-1,tc+s, s);}
    if (dr >= tr + s && dc < tc + s)
    // ���ⷽ���ڴ�������
    chessBoard(tr+s, tc, dr, dc, s);
    else {// �� t ��L�͹��Ƹ������Ͻ�
    board[tr + s][tc + s - 1] = t;
    // �������෽��
    chessBoard(tr+s, tc, tr+s, tc+s-1, s);}
    // �������½�������
    if (dr >= tr + s && dc >= tc + s)
    // ���ⷽ���ڴ�������
    chessBoard(tr+s, tc+s, dr, dc, s);
    else {// �� t ��L�͹��Ƹ������Ͻ�
    board[tr + s][tc + s] = t;
    // �������෽��
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
