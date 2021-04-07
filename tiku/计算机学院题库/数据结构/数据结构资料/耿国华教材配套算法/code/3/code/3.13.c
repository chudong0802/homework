#include "seqstack2.h"
#include "stdio.h"
#include <conio.h>


char ch;

int ExpEvaluation()/*����һ�����������ʽ��������ֵ��operatsign��operatdata�ֱ�Ϊ�����ջ��������ջ��OPSΪ���������*/
{
	char x,y;
	char op;
	int a,b,v;
	
	nStack operatdata;
	strStack operatsign;
	nInitStack(&operatdata);
	strInitStack(&operatsign);
	strPush(&operatsign,'#');
	
	printf("\nPlease input an expression (Ending with #) :\n");
    ch=getchar();

 	
 	strGetTop(&operatsign,&y);

 	while(ch!='#'||y!='#') /* strGetTop()ͨ������ֵ����ջ��Ԫ��*/
   	{
		if(!In(ch))                   /*�������������������*/
		{
			
			int temp; 		   /*������ֵ���ʱ����*/
			temp=ch-'0';
			/*���ַ�ת��Ϊʮ������*/
			fflush(stdin);
			ch=getchar();
			while(!In(ch))  //��ch��������������ĸ�λ���룬��ת��Ϊʮ������temp
			{
				temp=temp*10+ch-'0'; // ����������������ĸ�λת��Ϊʮ������
	 			fflush(stdin);
				ch=getchar();
			}  
   			nPush(&operatdata,temp);
		}
		else
      		switch(Compare(y,ch))
			{
	 			case '<': 
					strPush(&operatsign,ch); 
              		fflush(stdin);
					ch=getchar();
					break;
	 			case '=': 
					strPop(&operatsign,&x); 
					fflush(stdin);
					ch=getchar(); 
					break;
				case '>': 
					strPop(&operatsign,&op);
					nPop(&operatdata,&b);
					nPop(&operatdata,&a);
					v=Execute(a,op,b);  /* ��a��b����op���� */
					nPush(&operatdata,v);
					break;
			}
		strGetTop(&operatsign,&y);
	}
	nGetTop(&operatdata,&v);
	return (v);
}

void main()
{
	int result;   
    result=ExpEvaluation();
    printf("\n%d",result);
}
