int  ve[MAX_VERTEX_NUM];    /*ÿ����������緢��ʱ��*/

int TopoOrder(AdjList G,Stack *T) 
/* GΪ��������TΪ�����������е�ջ��SΪ������Ϊ0�Ķ����ջ*/
{   
	int count,i,j,k;  
	ArcNode *p;
	int indegree[MAX_VERTEX_NUM];  /*�������������*/
	Stack S;
    	InitStack(T);  
	InitStack(&S);   /*��ʼ��ջT,  S*/
    	FindID(G,indegree);  /*�������������*/
    	for(i=0;i<G.vexnum;i++)
		if(indegree[i]==0)	  
			Push(&S,i);
    	count=0;
    	for(i=0;i<G.vexnum;i++)
		ve[i]=0;   /*��ʼ�����緢��ʱ��*/
	while(!IsEmpty(&S))
	{
		Pop(&S,&j);
		Push(T,j);
		count++;
		p=G.vertex[j].firstarc;
		while(p!=NULL)
	    	{	
			k=p->adjvex;
			if(--indegree[k]==0)  
			Push(&S,k);   /*���������ȼ�Ϊ0������ջ*/
		    	if(ve[j]+p->Info.weight>ve[k])  
			ve[k]=ve[j]+p->Info.weight;
		    	p=p->nextarc;
	    	}  /*while*/
	} /*while*/
    	if(count<G.vexnum) 	
		return(Error);
    	else	
		return(Ok);
}
