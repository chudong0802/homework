
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  N 20
#define  M 2*N-1

typedef char* HuffmanCode[N+1];/*�洢N�����������봮��ͷָ������*/

typedef struct 
{
	unsigned int weight ; /* ������Ÿ�������Ȩֵ*/
	unsigned int parent, LChild,RChild ; /*ָ��˫�ס����ӽ���ָ��*/
}HTNode, HuffmanTree[M+1];   /*��̬�������飬�洢��������*/