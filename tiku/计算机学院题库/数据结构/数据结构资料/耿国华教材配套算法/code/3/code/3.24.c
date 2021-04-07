#include "seqqueue1.h"
#include <stdio.h>

void YangHuiTriangle( )
{ 
	int n;
	int i;
	int temp;
	int x;
	int N;
	SeqQueue Q;
	InitQueue(&Q);
	EnterQueue(&Q,1);  /* ��һ��Ԫ�����*/
	printf("please input N:");
	scanf("%d",&N);
	for(n=2;n<=N;n++)   /* ������n��Ԫ�ز���ӣ�ͬʱ��ӡ��n-1�е�Ԫ��*/
	{
		EnterQueue(&Q,1);   /* ��n�еĵ�һ��Ԫ�����*/
		for(i=1;i<=n-2;i++)  /* ���ö��е�n-1��Ԫ�ز�����n�е��м�n-2��Ԫ�ز����*/
		{
			DeleteQueue(&Q,&temp);
			printf("%6d",temp);     /* ��ӡ��n-1�е�Ԫ��*/
			GetHead(&Q,&x);
			temp=temp+x;      /*���ö��е�n-1��Ԫ�ز�����n��Ԫ��*/
			EnterQueue(&Q,temp);  
		}
		DeleteQueue (&Q,&x);  
		printf("%6d",x);    /* ��ӡ��n-1�е����һ��Ԫ��*/
		EnterQueue(&Q,1);   /* ��n�е����һ��Ԫ�����*/
		printf("\n");
	}
}

void main()
{
	YangHuiTriangle( );
}
