#include "seqstack1.h"
#include "stdio.h"

void BracketMatch(char *str);

void BracketMatch(char *str) /* str[]��Ϊ������ַ��������ö�ջ�����������ַ����е������Ƿ�ƥ��*/
{
	SeqStack S; 
	int i; 
	char ch;
	
	InitStack(&S);
	
	for(i=0; str[i]!='\0'; i++)   /*���ַ����е��ַ���һɨ��*/
	{
    	switch(str[i])
    	{
		case '(':
		case '[':
		case '{':
			Push(&S,str[i]);  
	        break;
      	case ')':
      	case ']':
      	case '}':
			if(IsEmpty(&S))
		    { 
				printf("\n�����Ŷ���!");  
		        return;
		    }
			else
			{
				GetTop(&S,&ch);
				if(Match(ch,str[i]))  /*��Match�ж����������Ƿ�ƥ��*/
					Pop(&S,&ch);      /*��ƥ��������ų�ջ*/
	            else
		        {
		            printf("\n��Ӧ���������Ų�ͬ��!");  
		            return;
		        }
			}
		}/*switch*/
	}/*for*/
	if(IsEmpty(&S))
		printf("\n����ƥ��!");
	else
		printf("\n�����Ŷ���!");
}

void main()
{
	char str[100];
	printf("please input:");
	gets(str);
	BracketMatch(str);
}
