int EnterQueue(SeqQueue *Q,QueueElementType x)
{  
	/*��Ԫ��x���*/
	if((Q->rear+1)%MAXSIZE==Q->front)  /*�����Ѿ�����*/
		return(FALSE);
	Q->element[Q->rear]=x;
	Q->rear=(Q->rear+1)%MAXSIZE;  /* �������ö�βָ�� */
	return(TRUE);  /*�����ɹ�*/
}
