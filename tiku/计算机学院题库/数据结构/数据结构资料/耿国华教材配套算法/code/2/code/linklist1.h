
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK   1
#define ERROR  0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef struct Node    /*������Ͷ���*/ 
{ 
	ElemType data;
	struct Node  * next;
}Node, *LinkList;  /* LinkListΪ�ṹָ������*/