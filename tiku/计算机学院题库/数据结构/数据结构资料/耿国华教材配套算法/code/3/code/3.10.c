int pushi(LinkStack top[M],int i,StackElementType x)
{
	/*��Ԫ��x�����i����ջ*/
	LinkStackNode  *temp;
	temp=(LinkStackNode *)malloc(sizeof(LinkStackNode));
	if(temp==NULL)  return(FALSE);   /* ����ռ�ʧ�� */
	temp->data=x;
	temp->next=top[i]->next;
	top[i]->next=temp;   /* �޸ĵ�ǰջ��ָ�� */ 
	return(TRUE);
}
