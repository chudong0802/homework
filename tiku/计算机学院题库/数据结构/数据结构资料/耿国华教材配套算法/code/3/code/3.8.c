int Push(LinkStack top,StackElementType x)  
{
	/* ������Ԫ��xѹ��ջtop�� */
	LinkStackNode *temp;
	temp=(LinkStackNode *)malloc(sizeof(LinkStackNode));
 	if(temp==NULL)  
		return(FALSE);   /* ����ռ�ʧ�� */
	temp->data=x;
	temp->next=top->next;
	top->next=temp;   /* �޸ĵ�ǰջ��ָ�� */ 
	return(TRUE);
}
