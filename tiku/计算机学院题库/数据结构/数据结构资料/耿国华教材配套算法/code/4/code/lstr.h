#include "stdio.h"
#include "stdlib.h"

/*��ʽ�洢��ʽ�µ�ģʽƥ�䣬ÿ���ַ���һ����ʾ*/

typedef struct Block{
	char   ch;
	struct Block   *next;
}Block;

typedef struct {
	Block   *head;
	Block   *tail;
	int     len;
}BLString;
