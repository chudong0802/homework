/*���ڽӾ���ʽʵ�������������*/
void DepthFirstSearch(AdjMatrix g,int v0)  /* ͼg Ϊ�ڽӾ�������AdjMatrix */ 
{
	visit(v0);
	visited[v0]=True;
	for(vj=0;vj<n;vj++)
	if(!visited[vj]&&g.arcs[v0][vj].adj==1) 
		DepthFirstSearch(g,vj);
}/* DepthFirstSearch */
