int Pop(LinkStack top,StackElementType *x)
{  
	/* ��ջtop��ջ��Ԫ�ص������ŵ�x��ָ�Ĵ洢�ռ��� */
	LinkStackNode *temp;
	temp=top->next;
	if(temp==NULL)  /*ջΪ��*/
		return(FALSE);
	top->next=temp->next;
	*x=temp->data;
	free(temp);   /* �ͷŴ洢�ռ� */
	return(TRUE);
}
