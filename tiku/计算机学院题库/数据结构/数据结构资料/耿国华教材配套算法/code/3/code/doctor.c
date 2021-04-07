#include "stdio.h"
#include "seqqueue.h"

void SeeDoctor()
{ 
	int flag=1;
	char ch;
	int n;
	SeqQueue Q;
	InitQueue(&Q);
 	
 	while(flag) 
 	{
   		printf("\n���������");
   		fflush(stdin);
		ch=getchar();
   		switch(ch) 
   		{
			case  'a':  
				printf("\n�����ţ�");
           		scanf("%d", &n);
           		EnterQueue(&Q, n);    /* ���µ��Ļ��߼�������к��� */
           		break;
			case  'n':  
				if(!IsEmpty(&Q)) 
				{ 
					DeleteQueue(&Q,&n);    /* ��һ���߳��Ӿ��� */
					printf("\n������Ϊ %d �Ĳ��˾���", n);
                }
                else  printf("\n�޲��˵Ⱥ����");
				break;
			case  'q':  
				printf("\n����ֹͣ�Һţ����в������ξ��");
				while (!IsEmpty(&Q))         /* ��ӡ����ʣ�໼��*/
				{ 
					DeleteQueue(&Q, &n);
					printf("%d  ",  n);
				}
				flag=0;
				break;
			default:  printf("\n�Ƿ����");
		}
	}
}

void main()
{
	SeeDoctor();
}