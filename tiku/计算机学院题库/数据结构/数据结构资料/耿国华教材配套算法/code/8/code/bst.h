#include <stdio.h>
#include <stdlib.h>

#define ENDKEY 0

typedef int KeyType;

typedef struct  node
{
	KeyType  key ; /*�ؼ��ֵ�ֵ*/
	struct node  *lchild,*rchild;/*����ָ��*/
}BSTNode, *BSTree;
