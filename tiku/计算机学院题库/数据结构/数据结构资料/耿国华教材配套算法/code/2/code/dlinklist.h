
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK   1
#define ERROR  0
#define TRUE 1
#define FALSE 0

typedef char ElemType;

typedef struct DNode
{
	ElemType data;
	struct DNode *prior, *next;
}DNode,	*DoubleList;

void CreateList(DoubleList L)
/*ͨ�������������Ԫ��ֵ������β�巨��������,�����ظõ�����ͷָ��L*/
{ 
	DNode *r, *s;
	char c;
	int   flag =1; /*����һ����־����ֵΪ1��������"$"ʱ��flagΪ0���������*/
	L->next=L;
	L->prior=L;
	r=L;              
	while(flag)         
	{
		c=getchar();
		if(c!='$')
		{
			s=(DNode*)malloc(sizeof(DNode));
			s->data=c;
			r->next=s;
			s->prior=r;
			r=s;
		}
		else
		{
			flag=0;
			r->next=L;   
			L->prior=r;
		}
	}   /*while*/
} 
