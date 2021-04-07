#include <malloc.h>
#include <stdio.h>

/*ʮ������Ľṹ���Ͷ������£�*/
typedef struct OLNode
{	
	int row,col;        /*����Ԫ�ص��к����±�*/
	ElementType value;
	struct OLNode *right;  /*����Ԫ�������б��б�ĺ������*/
	struct OLNode *down; 
}OLNode; *OLink;

typedef struct 
{	
	OLink *row_head;  /*�С��������ͷָ������*/
	OLink *col_head;
	int m,n,len;               /*ϡ����������������������Ԫ�صĸ���*/
}CrossList;

/*����ϡ������ʮ��������㷨*/

void CreateCrossList(CrossList *M)
{
	/*����ʮ������洢�ṹ������ϡ�����M*/
	scanf(&m,&n,&t);  /*����M������,�����ͷ���Ԫ�صĸ���*/
	M->m=m;
	M->n=n;
	M->len=t;
	if(!(M->row_head=(OLink *)malloc((m+1)sizeof(OLink)))) 
		exit(OVERFLOW);
	if(!(M->col_head=(OLink * )malloc((n+1)sizeof(OLink)))) 
		exit(OVERFLOW);
	M->row_head[ ]=M->col_head[ ]=NULL;   /*��ʼ���С���ͷָ�����������С�������Ϊ�յ�����*/
	for(scanf(&i,&j,&e);i!=0;scanf(&i,&j,&e))
	{
		if(!(p=(OLNode *)malloc(sizeof(OLNode)))) 
			exit(OVERFLOW);
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
