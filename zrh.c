#include "stdio.h"
#include "string.h"
#include "windows.h"
 
#define N 49//1表示棋子，只有黑色棋子
 
int chess[N+2][N+2];//定义棋盘大小
int chess0[N+2][N+2];//辅助棋盘
 
 
void Initialize();//初始化一个对局函数
void RunGame();//进行游戏
int Count(int i,int j);//计算生命周围的生命数量
void Data();//调用已存的游戏数据
 
main()
{
    system("mode con cols=99 lines=50");//设置窗口大小
    system("color 70");//设置颜色
    Initialize();//初始化一个对局函数
    RunGame();//进行游戏
}
 
void Initialize()//初始化一个对局函数
{
    Data();//调用已存的游戏数据
}
 
void Data()//调用已存的游戏数据
{
    int p=12;
    int l;
    for(l=-16;l<=16;l++)
        //if(l!=-8&&l!=0&&l!=4)
        chess[N/2+1][N/2+1+l]=1;
 
/*
//滑翔机
chess[1][3]=1;chess[2][1]=1;chess[2][3]=1;chess[3][2]=1;chess[3][3]=1;
*/
/*
//高斯帕滑翔机
chess[1][p+11]=1;chess[1][p+13]=1;
chess[2][p+10]=1;chess[2][p+13]=1;
chess[3][p+9]=1;chess[3][p+10]=1;chess[3][p+21]=1;chess[3][p+28]=1;
chess[4][p+1]=1;chess[4][p+2]=1;chess[4][p+7]=1;chess[4][p+8]=1;chess[4][p+12]=1;chess[4][p+21]=1;chess[4][p+27]=1;chess[4][p+29]=1;
chess[5][p+1]=1;chess[5][p+2]=1;chess[5][p+9]=1;chess[5][p+10]=1;chess[5][p+20]=1;chess[5][p+27]=1;chess[5][p+28]=1;chess[5][p+30]=1;
chess[6][p+10]=1;chess[6][p+13]=1;chess[6][p+16]=1;chess[6][p+17]=1;chess[6][p+27]=1;chess[6][p+28]=1;chess[6][p+30]=1;chess[6][p+31]=1;chess[6][p+35]=1;chess[6][p+36]=1;
chess[7][p+11]=1;chess[7][p+13]=1;chess[7][p+16]=1;chess[7][p+19]=1;chess[7][p+20]=1;chess[7][p+21]=1;chess[7][p+22]=1;chess[7][p+27]=1;chess[7][p+28]=1;chess[7][p+30]=1;chess[7][p+35]=1;chess[7][p+36]=1;
chess[8][p+16]=1;chess[8][p+17]=1;chess[8][p+18]=1;chess[8][p+19]=1;chess[8][p+27]=1;chess[8][p+29]=1;
chess[9][p+17]=1;chess[9][p+18]=1;chess[9][p+28]=1;
*/
}
 
void RunGame()//进行游戏
{
    int i,j,s=0;
    int flag=0;
    while(1)
    {Sleep(5000);
        system("cls");//清理屏幕，准备写入
        for(i=1;i<N+1;i++)
        {
            for(j=1;j<N+1;j++)
                if(chess[i][j]==1)
                    printf("█");//printf("■");
                else if(chess[i][j]==0)
                    printf("  ");
            printf("\n");
        }
        for(i=1;i<N+1;i++)
            for(j=1;j<N+1;j++)
            {
                s=Count(i,j);
                if(chess[i][j]==1)
                {
                    if(s<2)
                        chess0[i][j]=0;//如果一个生命周围的生命少于2个，它在回合结束后死亡。
                    else if(s>3)
                        chess0[i][j]=0;//如果一个生命周围的生命超过3个，它在回合结束后死亡。
                    else if(s==2||s==3)
                        chess0[i][j]=1;//如果一个生命周围有2或3个生命，它在回合结束时保持原样。
                }
                else if(chess[i][j]==0)
                {
                    if(s==3)
                        chess0[i][j]=1;//如果一个死格周围有3个生命，它在回合结束时获得生命。
                }
            }
         for(i=1;i<N+1;i++)
            for(j=1;j<N+1;j++)
                chess[i][j]=chess0[i][j];
        Sleep(5);
        if(flag==0)
        {
            getchar();
            flag=1;
        }
    }
}
 
int Count(int i,int j)//计算生命周围的生命数量
{
    int s=0,a,b;
    for(a=-1;a<=1;a++)
        for(b=-1;b<=1;b++)
            if(!(a==0&&b==0)&&chess[i+a][j+b]==1)
                s++;
    return s;
}
