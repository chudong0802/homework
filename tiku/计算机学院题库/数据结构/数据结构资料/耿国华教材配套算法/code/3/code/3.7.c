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
		if(S->top[1]==M)  return(FALSE);
		*x=S->Stack[S->top[1]];
		S->top[1]++;
		break;
	default:
		return(FALSE);
	}
	return(TRUE);
}
