#include "stdio.h"
#include "string.h"
#include "windows.h"
 
#define N 49//1��ʾ���ӣ�ֻ�к�ɫ����
 
int aa[N+2][N+2];//�������̴�С
int bb[N+2][N+2];//��������
 
 
void Initialize();//��ʼ��һ���Ծֺ���
void RunGame();//������Ϸ
int Count(int i,int j);//����������Χ����������
void Data();//�����Ѵ����Ϸ����
 
main()
{
    system("mode con cols=99 lines=50");//���ô��ڴ�С
    system("color 70");//������ɫ
    Initialize();//��ʼ��һ���Ծֺ���
    RunGame();//������Ϸ
}
 
void Initialize()//��ʼ��һ���Ծֺ���
{
    Data();//�����Ѵ����Ϸ����
}

void RunGame()//������Ϸ
{
    int i,j,s=0;
    int flag=0;
    while(1)
    {Sleep(1000);
        system("cls");//������Ļ��׼��д��
        for(i=1;i<N+1;i++)
        {
            for(j=1;j<N+1;j++)
                if(aa[i][j]==1)
                    printf("��");
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
                       bb[i][j]=0;//���һ��������Χ����������2�������ڻغϽ�����������
                    else if(s>3)
                        bb[i][j]=0;//���һ��������Χ����������3�������ڻغϽ�����������
                    else if(s==2||s==3)
                        bb[i][j]=1;//���һ��������Χ��2��3�����������ڻغϽ���ʱ����ԭ����
                }
                else if(aa[i][j]==0)
                {
                    if(s==3)
                       bb[i][j]=1;//���һ��������Χ��3�����������ڻغϽ���ʱ���������
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


int Count(int i,int j)//����������Χ����������
{
    int s=0,a,b;
    for(a=-1;a<=1;a++)
        for(b=-1;b<=1;b++)
            if(!(a==0&&b==0)&&aa[i+a][j+b]==1)
                s++;
    return s;
}

 
void Data()//�����Ѵ����Ϸ����
{
    int p=12;
    int l;
    for(l=-16;l<=16;l++)
        //if(l!=-8&&l!=0&&l!=4)
       aa[N/2+1][N/2+1+l]=1;
 }
