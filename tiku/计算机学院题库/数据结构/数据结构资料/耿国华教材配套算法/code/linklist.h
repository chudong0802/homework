
typedef int ElemType;
typedef struct Node    /*������Ͷ���*/ 
{ 
	ElemType data;
	struct Node  * next;
}Node, *LinkList;  /* LinkListΪ�ṹָ������*/

void CreateFromTail(LinkList L)
{ 
	Node *r, *s;
	char c;
	int   flag =1; /*����һ����־����ֵΪ1��������"$"ʱ��flagΪ0���������*/
	r=L;                /*rָ�붯ָ̬������ĵ�ǰ��β���Ա�����β���룬���ֵָ��ͷ���*/
	while(flag)         /*ѭ���������Ԫ��ֵ���������½��s�����β*/
	{
		scanf("%d",&c);
		if(c != -1)
		{
			s=(Node*)malloc(sizeof(Node));
			s->data=c;
			r->next=s;
			r=s;
		}
		else
		{
			flag=0;
			r->next=NULL;   /*�����һ������next������Ϊ�գ���ʾ����Ľ���*/
		}
	}   
} 
