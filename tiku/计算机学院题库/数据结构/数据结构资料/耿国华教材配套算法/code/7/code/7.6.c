/*���ڽӱ�ʽʵ�������������*/
void DepthFirstSearch(AdjList g,int v0)   /*ͼgΪ�ڽӱ�����AdjList */
{
	visit(v0);
	visited[v0]=True;
	p=g.vertex[v0].firstarc;
	while(p!=NULL)
	{
		if(!visited[p->adjvex])
			DepthFirstSearch(g,p->adjvex);
		p=p->nextarc;
	}
}/*DepthFirstSearch*/
