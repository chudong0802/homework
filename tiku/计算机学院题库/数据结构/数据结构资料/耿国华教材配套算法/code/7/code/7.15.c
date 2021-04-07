typedef unsigned int WeightType;
typedef WeightType AdjType;
typedef SeqList VertexSet;

ShortestPath_DJS(AdjMatrix g,int v0,WeightType dist[MAX_VERTEX_NUM],VertexSet path[MAX_VERTEX_NUM])
/* path[i]�д�Ŷ���i�ĵ�ǰ���·����dist[i]�д�Ŷ���i�ĵ�ǰ���·������*/
{ 
	VertexSet s;                  /*  sΪ���ҵ����·�����յ㼯�� */
	for(i=0;i<g.vexnum;i++)      /* ��ʼ��dist[i]��path [i]  */
	{ 
		InitList(&path[i]);
		dist[i]=g.arcs[v0][i].adj;
		if(dist[i]<INFINITY)
		{ 
			AddTail(&path[i],g.vexs[v0]);  /* AddTailΪ��β��Ӳ���*/
			AddTail(&path[i],g.vexs[i]);
        	}
	}
	InitList(&s);
	AddTail(&s,g.vexs[v0]);      /* ��v0���ɵ�һ�����ҵ����·�����յ�*/
/*���ϲ�������˶��������·������dist[ ]��·��path[],���㼯s[]�ĳ�ʼ������*/

/*���²���ͨ��n-1��ѭ�������ڶ��鶥�㼯V-S�еĶ��㰴�յ�������ʽ���뵽S�����У�����ôӶ���v0��������ͼ�����ඥ������·����*/
	for(t=1;t<=g.vexnum-1;t++)  /*��v0������n-1����������·��(n= g.vexnum )*/
	{ 
		min=INFINITY;
		for(i=0;i<g.vexnum;i++)
		if(!Member(g.vex[i],s)&&dist[i]<min)  
		{
			k =i; 
			min=dist[i];
		}
		AddTail(&s,g.vexs[k]);
		for(i=0;i<g.vexnum;i++)     /*����dist[i],  i��V-S*/
			if(!Member(g.vex[i],s)&&g.arcs[k][i].adj!=INFINITY&&(dist[k]+g.arcs[k][i].adj<dist[i]))
			{
				dist[i]=dist[k]+g.arcs[k][i].adj;
				path[i]=path[k];
				AddTail(&path[i],g.vexs[i]);      /* path[i]=path[k]��{Vi} */
			}
	}
}
