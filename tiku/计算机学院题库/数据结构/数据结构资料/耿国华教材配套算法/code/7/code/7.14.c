int CriticalPath(AdjList G)
{   
	ArcNode  *p; 
	int i,j,k,dut,ei,li; 
	char tag;
	int vl[MAX_VERTEX_NUM];    /*ÿ���������ٷ���ʱ��*/
	Stack T;
	if(!TopoOrder(G,&T))  
		return(Error);
    	for(i=0;i<G.vexnum;i++)
		vl[i]=ve[G.vexnum-1];   /*��ʼ�������¼�����ٷ���ʱ��*/
    	while(!IsEmpty(&T))   /*��������˳����������vlֵ*/
	{ 
		Pop(&T,&j);
	  	p=G.vertex[j].firstarc;
	    	while(p!=NULL)
	    	{
			k=p->adjvex; 
			dut=p->weight;
			if(vl[k]-dut<vl[j])  
			vl[j]=vl[k]-dut;
            		p=p->nextarc;
		} /* while */
	} /* while*/
    	for(j=0;j<G.vexnum;j++)   /*��ei,li�͹ؼ��*/
	{ 
		p=G.vertex[j].firstarc;
	    	while(p!=NULL)
	    	{ 
			k=p->Adjvex; 
			dut=p->Info.weight;
	        	ei=ve[j];li=vl[k]-dut; 
			tag=(ei==li)?'*':' ';
			printf("%c,%c,%d,%d,%d,%c\n",G.vertex[j].data,G.vertex[k].data,dut,ei,li,tag);  /*����ؼ��*/
	        	p=p->nextarc;
	    	} /*while*/
	} /* for */
	return(Ok);
} /*CriticalPath*/
