int DeleteQueue(SeqQueue *Q,QueueElementType *x)
{ 
	/*ɾ�����еĶ�ͷԪ�أ���x������ֵ*/
	if(Q->front==Q->rear)  /*����Ϊ��*/
		return(FALSE);
	*x=Q->element[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;  /*�������ö�ͷָ��*/
	return(TRUE);  /*�����ɹ�*/
}
