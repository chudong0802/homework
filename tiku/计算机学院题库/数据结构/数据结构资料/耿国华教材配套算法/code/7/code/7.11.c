int TopoSort(AdjList G)
{ 
	Stack S;
	int indegree[MAX_VERTEX_NUM];
	int i,count,k;
    	ArcNode *p;
    	FindID(G,indegree);  /*����������*/
    	InitStack(&S);       /*��ʼ������ջ*/
    	for(i=0;i<G.vexnum;i++)
		if(indegree[i]==0) 
			Push(&S,i);    /*�����Ϊ0�Ķ�����ջ*/
    	count=0;
    	while(!IsEmpty(S)) 
    	{
		Pop(&S,&i);
		printf("%c",G.vertex[i].data);
		count++;  /*���i�Ŷ��㲢����*/
        	p=G.vertexes[i].firstarc;
		while(p!=NULL)
		{ 
			k=p->adjvex;
            		indegree[k]--;      /*i�Ŷ����ÿ���ڽӵ����ȼ�1*/
		    	if(indegree[k]==0)  
			Push(&S, k);  /*����ȼ�Ϊ0������ջ*/
		    	p=p->nextarc;
		}
	} /*while*/
    	if(count<G.vexnum)  
		return(Error);  /*������ͼ���л�·*/
    	else  
		return(Ok);
}
