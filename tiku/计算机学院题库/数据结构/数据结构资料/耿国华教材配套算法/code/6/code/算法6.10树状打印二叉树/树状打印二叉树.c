
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
		*bt=(BiTree)malloc(sizeof(BiTNode)); //生成一个新结点
        (*bt)->data=ch;
        CreateBiTree(&((*bt)->LChild)); //生成左子树
        CreateBiTree(&((*bt)->RChild)); //生成右子树
	}
}

void PrintTree(BiTree bt,int nLayer)  /* 按竖向树状打印的二叉树 */
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
	printf("按扩展先序遍历序列建立二叉树，请输入序列:\n");
    CreateBiTree(&T);

	PrintTree(T,layer);
	getch();
}
