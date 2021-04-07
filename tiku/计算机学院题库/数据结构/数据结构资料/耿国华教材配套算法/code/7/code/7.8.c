/*�������������ͨ��ͼ���㷨���£�*/
void BreadthFirstSearch(Graph g,int v0)  /*�����������ͼg��v0���ڵ���ͨ��ͼ*/
{
	visit(v0); 
	visited[v0]=True;
	InitQueue(&Q);  /*��ʼ���ն�*/ 
	EnterQueue(&Q,v0);/* v0����*/
	while(!Empty(Q))
	{ 
		DeleteQueue(&Q,&v);  /*��ͷԪ�س���*/
		w=FirstAdjVertex(g,v);  /*��v�ĵ�һ���ڽӵ�*/
		while(w!=-1)
		{	
			if(!visited(w))
			{ 
				visit(w); 
				visited[w]=True;
				EnterQueue(&Q, w);
            		}
			w=NextAdjVertex(g,v,w);  /*��v�����w����һ���ڽӵ�*/
		}
	}
}
