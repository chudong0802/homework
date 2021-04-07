
#include <stdio.h>
#include <stdlib.h>

#define RADIX 10
#define KEY_SIZE 6
#define LIST_SIZE 20

typedef int KeyType;
typedef int OtherType;

typedef struct 
{
	KeyType key[KEY_SIZE];      /* �ӹؼ������� */ 
	OtherType other_data;        /* ���������� */ 
	
	int  next;                   /* ��̬���� */ 
} RecordType1;

typedef struct 
{
	RecordType1  r[LIST_SIZE+1];  /* r[0]Ϊͷ��� */
	int length;
	int keynum;
}SLinkList;                  /* ��̬���� */

typedef int PVector[RADIX];
