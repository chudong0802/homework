int GetTop(SeqStack *S, StackElementType *x)
{  
	/* ��ջS��ջ��Ԫ�ص������ŵ�x��ָ�Ĵ洢�ռ��У���ջ��ָ�뱣�ֲ��� */
	if(S->top==-1)  /*ջΪ��*/
		return(FALSE);
	else
	{
		*x = S->elem[S->top];
		return(TRUE);
	}	
}
