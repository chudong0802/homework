#define TRUE 1
#define FALSE 0
#define Stack_Size 50

/*˳��ջ*/

typedef struct
{
	StackElementType elem[Stack_Size]; /*�������ջ��Ԫ�ص�һά����*/
	int top;          		/*�������ջ��Ԫ�ص��±꣬topΪ-1��ʾ��ջ*/
}SeqStack;


/*��ʼ��*/
void InitStack(SeqStack *S)
{
	/*����һ����ջS*/
  	S->top = -1;
}

/*��ջ��*/
int IsEmpty(SeqStack *S) /*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
{
	return(S->top==-1?TRUE:FALSE);
}

/*��ջ��*/
int IsFull(SeqStack *S)	/*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
{
	return(S->top==Stack_Size-1?TRUE:FALSE);
}

int Push(SeqStack *S,StackElementType x)
{
	if(S->top==Stack_Size-1)  
		return(FALSE);  /*ջ����*/
	S->top++;
	S->elem[S->top] = x;
	return(TRUE);
}

int Pop(SeqStack *S,StackElementType *x)
{  
	/* ��ջS��ջ��Ԫ�ص������ŵ�x��ָ�Ĵ洢�ռ��� */
	if(S->top == -1)  /*ջΪ��*/
		return(FALSE);
	else
	{
  		*x = S->elem[S->top];
		S->top--;    /* �޸�ջ��ָ�� */
  		return(TRUE);
	}
}

/*ȡջ��Ԫ�ء�*/
int GetTop(SeqStack *S,StackElementType *x)
{  
	/* ��ջS��ջ��Ԫ�ص������ŵ�x��ָ�Ĵ洢�ռ��У���ջ��ָ�뱣�ֲ��� */
	if(S->top == -1)  /*ջΪ��*/
		return(FALSE);
	else
	{
  		*x = S->elem[S->top];
  		return(TRUE);
	}	
}

/*����ƥ��*/
int Match(char ch,char str)
{		
	if(ch=='(' && str==')')
	{
		return TRUE;
	}
	else if(ch=='[' && str==']')
	{
		return TRUE;
	}
	else if(ch=='{' && str=='}')
	{
		return TRUE;
	}
	else 
		return FALSE;
}