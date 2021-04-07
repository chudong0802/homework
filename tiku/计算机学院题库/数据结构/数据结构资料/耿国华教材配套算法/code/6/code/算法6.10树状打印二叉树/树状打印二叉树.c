
#include <stdio.h>
#include <malloc.h>
#include <conio.h>

typedef char DataType;

typedef struct Node
{
	DataType data;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode, *BiTree;


void CreateBiTree(BiTree *bt)
{
	char ch;
	ch = getchar();
    if(ch=='/') *bt=NULL;
    else 
	{
		*bt=(BiTree)malloc(sizeof(BiTNode)); //����һ���½��
        (*bt)->data=ch;
        CreateBiTree(&((*bt)->LChild)); //����������
        CreateBiTree(&((*bt)->RChild)); //����������
	}
}

void PrintTree(BiTree bt,int nLayer)  /* ��������״��ӡ�Ķ����� */
{
	if(bt == NULL) return;
	PrintTree(bt->RChild,nLayer+1);
	for(int i=0;i<nLayer;i++)
		printf("  ");
	printf("%c\n",bt->data);
	PrintTree(bt->LChild,nLayer+1);
}

void main()
{
	BiTree T;
	int layer;
	layer = 0;
	printf("����չ����������н���������������������:\n");
    CreateBiTree(&T);

	PrintTree(T,layer);
	getch();
}
