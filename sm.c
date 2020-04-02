#include "stdio.h"
#include "string.h"
#include "windows.h"
 
#define N 49//1表示棋子，只有黑色棋子
 
int aa[N+2][N+2];//定义棋盘大小
int bb[N+2][N+2];//辅助棋盘
 
 
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

void RunGame()//进行游戏
{
    int i,j,s=0;
    int flag=0;
    while(1)
    {Sleep(1000);
        system("cls");//清理屏幕，准备写入
        for(i=1;i<N+1;i++)
        {
            for(j=1;j<N+1;j++)
                if(aa[i][j]==1)
                    printf("◆");
                else if(aa[i][j]==0)
                    printf("  ");
            printf("\n");
        }
        for(i=1;i<N+1;i++)
            for(j=1;j<N+1;j++)
            {
                s=Count(i,j);
                if(aa[i][j]==1)
                {
                    if(s<2)
                       bb[i][j]=0;//如果一个生命周围的生命少于2个，它在回合结束后死亡。
                    else if(s>3)
                        bb[i][j]=0;//如果一个生命周围的生命超过3个，它在回合结束后死亡。
                    else if(s==2||s==3)
                        bb[i][j]=1;//如果一个生命周围有2或3个生命，它在回合结束时保持原样。
                }
                else if(aa[i][j]==0)
                {
                    if(s==3)
                       bb[i][j]=1;//如果一个死格周围有3个生命，它在回合结束时获得生命。
                }
            }
         for(i=1;i<N+1;i++)
            for(j=1;j<N+1;j++)
                aa[i][j]=bb[i][j];
 
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
            if(!(a==0&&b==0)&&aa[i+a][j+b]==1)
                s++;
    return s;
}

 
void Data()//调用已存的游戏数据
{
    int p=12;
    int l;
    for(l=-16;l<=16;l++)
        //if(l!=-8&&l!=0&&l!=4)
       aa[N/2+1][N/2+1+l]=1;
 }
