#include <malloc.h>
#include <stdio.h>
#define NULL 0;
/*ʮ������Ľṹ���Ͷ������£�*/
typedef struct OLNode
{	
	int row,col;        /*����Ԫ�ص��к����±�*/
	int value;
	struct OLNode *right;  /*����Ԫ�������б��б�ĺ������*/
	struct OLNode *down; 
}OLNode,* OLink;

typedef struct 
{	
	OLink *row_head;  /*�С��������ͷָ������*/
	OLink *col_head;
	int m,n,len;               /*ϡ����������������������Ԫ�صĸ���*/
}CrossList;

