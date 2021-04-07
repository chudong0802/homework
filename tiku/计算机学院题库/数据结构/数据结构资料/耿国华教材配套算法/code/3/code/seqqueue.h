#define  TRUE 1
#define  FALSE 0

#define MAXSIZE 50  /*���е���󳤶�*/

typedef struct
{
	QueueElementType  element[MAXSIZE];  /* ���е�Ԫ�ؿռ�*/
	int front;  /*ͷָ��ָʾ��*/
	int rear;  /*βָ��ָʾ��*/
}SeqQueue;


/*��ʼ������*/
void InitQueue(SeqQueue *Q)
{  
	/* ��*Q��ʼ��Ϊһ���յ�ѭ������ */
	Q->front=Q->rear=0;
}

/*��Ӳ���*/
int EnterQueue(SeqQueue *Q, QueueElementType x)
{  
	/*��Ԫ��x���*/
	if((Q->rear+1)%MAXSIZE==Q->front)  /*�����Ѿ�����*/
		return(FALSE);
	Q->element[Q->rear]=x;
	Q->rear=(Q->rear+1)%MAXSIZE;  /* �������ö�βָ�� */
	return(TRUE);  /*�����ɹ�*/
}

/*���Ӳ���*/
int DeleteQueue(SeqQueue *Q, QueueElementType *x)
{ 
	/*ɾ�����еĶ�ͷԪ�أ���x������ֵ*/
	if(Q->front==Q->rear)  /*����Ϊ��*/
		return(FALSE);
	*x=Q->element[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;  /*�������ö�ͷָ��*/
	return(TRUE);  /*�����ɹ�*/
}

int GetHead(SeqQueue *Q, QueueElementType *x)
{ 
	/*��ȡ���еĶ�ͷԪ�أ���x������ֵ*/
	if(Q->front==Q->rear)  /*����Ϊ��*/
		return(FALSE);
	*x=Q->element[Q->front];
	return(TRUE);  /*�����ɹ�*/
}

int IsEmpty(SeqQueue *Q)
{ 
	/*��ȡ���еĶ�ͷԪ�أ���x������ֵ*/
	if(Q->front==Q->rear)  /*����Ϊ��*/
		return(TRUE);
	else
		return(FALSE);  /*�����ɹ�*/
}