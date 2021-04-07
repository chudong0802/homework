#define  M  10   /*M����ջ*/
#define TRUE 1
#define FALSE 0

typedef struct node
{
	StackElementType data;
	struct node *next;
}LinkStackNode,  *LinkStack;
LinkStack  top[M];

/*��i��ջ�Ľ�ջ����*/
int  pushi(LinkStack top[M],int i,StackElementType x)
{
	/*��Ԫ��x�����i����ջ*/
	LinkStackNode  *temp;
	temp=(LinkStackNode * )malloc(sizeof(LinkStackNode));
	if(temp==NULL)  
		return(FALSE);   /* ����ռ�ʧ�� */
	temp->data=x;
	temp->next=top[i]->next;
	top[i]->next=temp;   /* �޸ĵ�ǰջ��ָ�� */ 
	return(TRUE);
}

/*��i��ջԪ�صĳ�ջ����*/
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
