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
