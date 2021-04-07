#define TRUE 1
#define FALSE 0
#define M 100

typedef struct
{
	StackElementType Stack[M];
	StackElementType top[2];  /*top[0]��top[1]�ֱ�Ϊ����ջ��ָʾ��*/
}DqStack;

/*��ʼ��������*/
void InitStack(DqStack *S)
{
	S->top[0]=-1;
	S->top[1]=M;
}

/*��ջ������*/
int Push(DqStack *S,StackElementType x,int i)
{
	/*������Ԫ��xѹ��i�Ŷ�ջ*/
	if(S->top[0]+1==S->top[1]) /*ջ����*/
		return(FALSE);
	switch(i)
	{
	case 0:
		S->top[0]++;
		S->Stack[S->top[0]]=x;
		break;
	case 1:
		S->top[1]--;
		S->Stack[S->top[1]]=x;
		break;
	default:  /*��������*/
        return(FALSE)
 	}
	return(TRUE);
}

/*��ջ������*/
int Pop(DqStack *S,StackElementType *x,int i)
{
	/* ��i �Ŷ�ջ�е���ջ��Ԫ�ز��͵�x�� */
	switch(i)
	{
	case 0:
		if(S->top[0]==-1)  
			return(FALSE);
		*x=S->Stack[S->top[0]];
		S->top[0]--;
		break;
	case 1:
		if(S->top[1]==M)  
			return(FALSE);
		*x=S->Stack[S->top[1]];
		S->top[1]++;
		break;
	default:
		return(FALSE);
	}
	return(TRUE);
}
