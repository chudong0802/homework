int Pop(LinkStack top[M],int i,StackElementType *x)
{  
	/* ��ջtop��ջ��Ԫ�ص������ŵ�x��ָ�Ĵ洢�ռ��� */
	LinkStackNode *temp;
	temp=top[i]->next;
	if(temp==NULL)  /*��i��ջΪ��ջ*/
		return(FALSE);
	top[i]->next=temp->next;
	*x=temp->data;
	free(temp);   /* �ͷŴ洢�ռ� */
	return(TRUE);
}
