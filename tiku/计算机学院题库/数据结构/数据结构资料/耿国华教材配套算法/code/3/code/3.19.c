int EnterQueue(LinkQueue *Q,QueueElementType x)
{  
	/* ������Ԫ��x���뵽����Q�� */
	LinkQueueNode  *NewNode;
	NewNode=(LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if(NewNode!=NULL)
	{
		NewNode->data=x;
		NewNode->next=NULL;
		Q->rear->next=NewNode;
	  	Q->rear=NewNode;
		return(TRUE);
	}
	else  return(FALSE);    /* �����*/
}
