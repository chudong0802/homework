int DeleteQueue(LinkQueue *Q,QueueElementType *x)
{  
	/* ������Q�Ķ�ͷԪ�س��ӣ�����ŵ�x��ָ�Ĵ洢�ռ��� */
	LinkQueueNode *p;
	if(Q->front==Q->rear)
		return(FALSE);
	p=Q->front->next;
	Q->front->next=p->next;  /* ��ͷԪ��p���� */
	if(Q->rear==p)  /* �������ֻ��һ��Ԫ��p����p���Ӻ��Ϊ�ն� */
	Q->rear=Q->front;  
	*x=p->data;
	free(p);   /* �ͷŴ洢�ռ� */
	return(TRUE);	
}
