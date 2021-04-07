#define TRUE 1
#define FALSE 0
#define Stack_Size 50


/*˳��ջ-����*/
typedef struct
{
	int elem[Stack_Size];  /*�������ջ��Ԫ�ص�һά����*/
	int  top;          /*�������ջ��Ԫ�ص��±꣬topΪ-1��ʾջ�ǿ�ջ*/
}nStack;

/*��ʼ��*/
void  nInitStack(nStack *S)
{
/*����һ����ջS*/
  	S->top=-1;
}

/*��ջ��*/
int nIsEmpty(nStack *S)	/*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
{
	return(S->top==-1?TRUE:FALSE);
}

/*��ջ��*/
int nIsFull(nStack *S)	/*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
{
	return(S->top==Stack_Size-1?TRUE:FALSE);
}

int nPush(nStack * S, int x)
{
	if(S->top== Stack_Size-1)  return(FALSE);  /*ջ����*/
	S->top++;
	S->elem[S->top]=x;
	return(TRUE);
}

int nPop(nStack * S, int *x)
{  /* ��ջS��ջ��Ԫ�ص������ŵ�x��ָ�Ĵ洢�ռ��� */
	if(S->top==-1)  /*ջΪ��*/
		return(FALSE);
	else
	{
  		*x= S->elem[S->top];
		S->top--;    /* �޸�ջ��ָ�� */
  		return(TRUE);
	}
}

int nGetTop(nStack *S, int *x)
{  /* ��ջS��ջ��Ԫ�ص������ŵ�x��ָ�Ĵ洢�ռ��У���ջ��ָ�뱣�ֲ��� */
	if(S->top==-1)  /*ջΪ��*/
		return(FALSE);
	else
	{
  		*x = S->elem[S->top];
  		return(TRUE);
	}
}


/*˳��ջ-�ַ���*/
typedef struct
{
	char elem[Stack_Size];  /*�������ջ��Ԫ�ص�һά����*/
	int  top;          /*�������ջ��Ԫ�ص��±꣬topΪ-1��ʾջ�ǿ�ջ*/
}strStack;

/*��ʼ��*/
void strInitStack(strStack *S)
{
/*����һ����ջS*/
  	S->top=-1;
}

/*��ջ��*/
int strIsEmpty(strStack *S)	/*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
{
	return(S->top==-1?TRUE:FALSE);
}

/*��ջ��*/
int strIsFull(strStack *S)	/*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
{
	return(S->top==Stack_Size-1?TRUE:FALSE);
}

char strPush(strStack * S, char x)
{
	if(S->top== Stack_Size-1)  return(FALSE);  /*ջ����*/
	S->top++;
	S->elem[S->top]=x;
	return(TRUE);
}

char strPop(strStack * S, char *x)
{  /* ��ջS��ջ��Ԫ�ص������ŵ�x��ָ�Ĵ洢�ռ��� */
	if(S->top==-1)  /*ջΪ��*/
		return(FALSE);
	else
	{
  		*x= S->elem[S->top];
		S->top--;    /* �޸�ջ��ָ�� */
  		return(TRUE);
	}
}

int strGetTop(strStack *S, char *x)
{  /* ��ջS��ջ��Ԫ�ص������ŵ�x��ָ�Ĵ洢�ռ��У���ջ��ָ�뱣�ֲ��� */
	if(S->top==-1)  /*ջΪ��*/
		return(FALSE);
	else
	{
  		*x = S->elem[S->top];
  		return(TRUE);
	}
}

/*���ܺ���*/
int Match(char ch,char str)
{		
	if(ch=='('&&str==')')
	{
		return TRUE;
	}
	else if(ch=='['&&str==']')
	{
		return TRUE;
	}
	else if(ch=='{'&&str=='}')
	{
		return TRUE;
	}
	else return FALSE;
}

int In(char ch)
{
	if(ch=='+')
	{
		return TRUE;	
	}
	else if(ch=='-') 
	{
		return TRUE;	
	}
	else if(ch=='*')
	{
		return TRUE;	
	}
	else if(ch=='/')
	{
		return TRUE;	
	}
	else if(ch=='(')
	{
		return TRUE;	
	}
	else if(ch==')')
	{
		return TRUE;	
	}
	else if(ch=='#')
	{
		return TRUE;	
	}
	else return FALSE;
}

char Compare(char x,char ch)
{
	switch(x)
	{
	case '+':
		if(ch=='+'||ch=='-'||ch==')'||ch=='#')
			return '>';	
		else if(ch=='*'||ch=='/'||ch=='(')
				return '<';	
		break;
	case '-':
		if(ch=='+'||ch=='-'||ch==')'||ch=='#')
			return '>';	
		else if(ch=='*'||ch=='/'||ch=='(')
			return '<';	
		break;
	case '*':
		if(ch=='(')
		{
			return '<';
		}
		else
		{
			return '>';
		}
		break;
	case '/':
		if(ch=='(')
				return '<';	
		else
				return '>';	
		break;
	case '(':
		if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='(')
			return '<';	
		else if(ch==')')
			return '=';	
		else if(ch=='#')
			return '0';	
		break;
	case ')':
		if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch==')'||ch=='#')
			return '>';	
		else if(ch=='(')
			return '0';	
		break;
	case '#':
		if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='(')
			return '<';	
		else if(ch=='#')
			return '=';	
		else if(ch==')')
			return '0';	
		break;	
	default:
		return '0';
		break;
	}

}	

int Execute(int a,char op,int b)
{
	switch(op)
	{
	case '+':
		return (a+b);
		break;
	case '-':
		return (a-b);
		break;
	case '*':
		return (a*b);
		break;
	case '/':
		return (a/b);
		break;
	}
}
