int Pop(SeqStack *S,StackElementType *x)
{  
	/* ��ջS��ջ��Ԫ�ص������ŵ�x��ָ�Ĵ洢�ռ��� */
	if(S->top= =-1)  /*ջΪ��*/
		return(FALSE);
	else
	{
		*x=S->elem[S->top];
		S->top--;    /* �޸�ջ��ָ�� */
  		return(TRUE);
	}
}
