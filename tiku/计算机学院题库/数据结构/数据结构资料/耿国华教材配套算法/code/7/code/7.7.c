/*�÷ǵݹ����ʵ�������������*/
void DepthFirstSearch(Graph g,int v0)  /*��v0���������������ͼg*/
{
	InitStack(S);  /*��ʼ����ջ*/
	Push(S,v0);
	while(!Empty(S))
	{ 
		v=Pop(S);  
		if(!visited(v))  /*ջ�п������ظ����*/
		{ 
			visit(v);  
			visited[v]=True; 
		}
		w=FirstAdjVertex(g,v);  /*��v�ĵ�һ���ڽӵ�*/
		while(w!=-1)
		{	
			if(!visited(w))  
				Push(S,w);
			w=NextAdjVertex(g,v,w);  /*��v�����w����һ���ڽӵ�*/
		}
	}
}
