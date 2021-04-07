typedef SeqList VertexSet;

ShortestPath_Floyd(AdjMatrix g, 
	WeightType dist[MAX_VERTEX_NUM][MAX_VERTEX_NUM],  
	VertexSet path[MAX_VERTEX_NUM][MAX_VERTEX_NUM])
/* gΪ��Ȩ����ͼ���ڽӾ����ʾ���� path [i][j]Ϊvi��vj�ĵ�ǰ���·����dist[i][j]Ϊvi��vj�ĵ�ǰ���·������*/
{
	int i,j,k;
	for(i=0;i<g.vexnum;i++)    
		for(j=0;j<g.vexnum;j++)
		{         /*��ʼ��dist[i][j]��path[i][j] */
			InitList(&path[i][j]);
			dist[i][j]=g.arcs[i][j].adj;
			if(dist[i][j]<INFINITY)  
			{
				AddTail(&path[i][j],g.vexs[i]);
				AddTail(&path[i][j],g.vexs[j]);
			}
		}
	for(k=0;k<g.vexnum;k++)
		for(i=0;i<g.vexnum;i++)
			for(j=0;j<g.vexnum;j++)
				if(dist[i][k]+dist[k][j]<dist[i][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
					paht[i][j]=JoinList(paht[i][k],paht[k][j]);  
				}    /*JoinListΪ�ϲ����Ա����*/
}
