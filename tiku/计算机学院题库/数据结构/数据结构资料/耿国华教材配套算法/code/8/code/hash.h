#include <stdio.h>
#include <stdlib.h>

#define  m   13
#define  NULLKEY  0
typedef  int  KeyType;    /* ����ؼ���Ϊ���� */
typedef  struct
{
	KeyType  key;
}RecordType;

typedef  RecordType  HashTable[m];