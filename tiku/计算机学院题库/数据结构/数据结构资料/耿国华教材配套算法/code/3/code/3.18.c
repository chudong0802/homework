int InitQueue(LinkQueue *Q)
{ 
	/* ��Q��ʼ��Ϊһ���յ������� */
	Q->front=(LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if(Q->front!=NULL)
	{
		Q->rear=Q->front;
		Q->front->next=NULL;
 		return(TRUE);
	}
	else  	return(FALSE);    /* �����*/
}
