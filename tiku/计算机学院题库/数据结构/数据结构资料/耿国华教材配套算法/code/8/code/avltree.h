#include <stdio.h>
#include <stdlib.h>

#define ENDKEY 0

typedef int KeyType;

typedef struct  node
{
	KeyType  key ; /*�ؼ��ֵ�ֵ*/
	int bf;
	struct node  *lchild,*rchild;/*����ָ��*/
}AVLTNode, *AVLTree;

