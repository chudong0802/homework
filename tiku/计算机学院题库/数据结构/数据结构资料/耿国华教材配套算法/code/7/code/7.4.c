void  DepthFirstSearch(Graph g,int v0) /*��ȱ���v0���ڵ���ͨ��ͼ*/
{
	visit(v0);
	visited[v0]=True;/*���ʶ���v0�����÷��ʱ�־������Ӧ����ֵ*/
	w=FirstAdjVertex(g,v0);
	while(w!=-1)  /*�ڽӵ����.*/
	{ 
		if(!visited[w])   
			DepthFirstSearch(g,w);  /*�ݹ����DepthFirstSearch*/
		w=NextAdjVertex(g,v0,w); /*����һ���ڽӵ�*/
	}
} /*DepthFirstSearch*/
