/*����ϡ������ʮ��������㷨*/

#include "crosslistarray.h"

void CreateCrossList(CrossList *M)
{
	int m,n,t;
	OLNode *p,*q;
	int i,j,e;
	/*����ʮ������洢�ṹ������ϡ�����M*/
	printf("����M������,�����ͷ���Ԫ�صĸ���\n");
	scanf("%d,%d,%d",&m,&n,&t);  /*����M������,�����ͷ���Ԫ�صĸ���*/
	M->m=m;
	M->n=n;
	M->len=t;
	if(!(M->row_head=(OLink *)malloc((m+1)*sizeof(OLink)))) 
		printf("error");
	if(!(M->col_head=(OLink *)malloc((n+1)*sizeof(OLink)))) 
		printf("error");
	M->row_head=M->col_head=NULL;   /*��ʼ���С���ͷָ�����������С�������Ϊ�յ�����*/

	printf("����\n");
	for(scanf("%d,%d,%d",&i,&j,&e);i!=0;scanf("%d,%d,%d",&i,&j,&e))
	{
		if(!(p=(OLNode *)malloc(sizeof(OLNode)))) 
			printf("error");
		p->row=i;
		p->col=j;
		p->value=e;  /*���ɽ��*/
		if(M->row_head[i]==NULL)   
			M->row_head[i]=p;
		else
		{  
			/*Ѱ���б��еĲ���λ��*/
			for(q=M->row_head[i];q->right&&q->right->col<j;q=q->right);  /*��ѭ����*/
			p->right=q->right; 
			q->right=p;  /*��ɲ���*/
		}
		if(M->col_head[j]==NULL)   
			M->col_head[j]=p;
		else
		{  
			/*Ѱ���б��еĲ���λ��*/
			for(q=M->col_head[j];q->down&&q->down->row<i;q=q->down);  /*��ѭ����*/
			p->down=q->down; 
			q->down=p;   /*��ɲ���*/
		}
	}
}

void main()
{
	CrossList M;

	CreateCrossList(&M);
}