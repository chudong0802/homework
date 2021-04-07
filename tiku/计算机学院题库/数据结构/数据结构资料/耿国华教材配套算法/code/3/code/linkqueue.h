#define  TRUE 1
#define  FALSE 0

#define MAXSIZE 50  /*���е���󳤶�*/

typedef struct Node
{
	QueueElementType data;     /*������*/
	struct Node *next;     /*ָ����*/
}LinkQueueNode;

typedef struct 
{
	LinkQueueNode *front;
	LinkQueueNode *rear;
}LinkQueue;

/*��ʼ��������*/
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
	else return(FALSE);    /* �����*/
}

/*��Ӳ�����*/
int EnterQueue(LinkQueue *Q,QueueElementType x)
{  
	/* ������Ԫ��x���뵽����Q�� */
	LinkQueueNode *NewNode;
	NewNode=(LinkQueueNode * )malloc(sizeof(LinkQueueNode));
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

/*���Ӳ�����*/
int DeleteQueue(LinkQueue *Q,QueueElementType *x)
{  
	/* ������Q�Ķ�ͷԪ�س��ӣ�����ŵ�x��ָ�Ĵ洢�ռ��� */
	LinkQueueNode * p;
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

int GetHead(SeqQueue *Q, int *x)
{ 
	/*��ȡ���еĶ�ͷԪ�أ���x������ֵ*/
	if(Q->front==Q->rear)  /*����Ϊ��*/
		return(FALSE);
	*x=Q->element[Q->front];
	return(TRUE);  /*�����ɹ�*/
}