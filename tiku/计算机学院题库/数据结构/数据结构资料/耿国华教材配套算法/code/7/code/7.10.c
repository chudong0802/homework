/*����ķ�㷨�������£�*/
struct 
{
	VertexData adjvex;
    	int lowcost;
}closedge[MAX_VERTEX_NUM];   /* ����С������ʱ�ĸ�������*/

MiniSpanTree_Prim(AdjMatrix gn,VertexData u)
/*�Ӷ���u������������ķ�㷨������ͨ��gn ����С���������������������ÿ����*/
{
	k=LocateVertex(gn, u);
	closedge[k].lowcost=0;   /*��ʼ����U={u} */
	for(i=0;i<gn.vexnum;i++)    
		if (i!=k)    /*��V-U�еĶ���i����ʼ��closedge[i]*/
	    	{
			closedge[i].adjvex=u; 
			closedge[i].lowcost=gn.arcs[k][i].adj;
		}
	for(e=1;e<=gn.vexnum-1;e++)    /*��n-1����(n= gn.vexnum) */
	{
		k0=Minium(closedge);     /* closedge[k0]�д��е�ǰ��С�ߣ�u0,v0������Ϣ*/
		u0=closedge[k0].adjvex;   /* u0��U*/
		v0=gn.vexs[k0];          /* v0��V-U*/
	    	printf("%d,%d",u0, v0);    /*����������ĵ�ǰ��С�ߣ�u0,v0��*/
		closedge[k0].lowcost=0;     /*������v0����U����*/
		for(i=0;i<vexnum;i++)    /*�ڶ���v0����U֮�󣬸���closedge[i]*/
			if(gn.arcs[k0][i].adj<closedge[i].lowcost)
            		{ 
				closedge[i].lowcost=gn.arcs[k0][i].adj;
				closedge[i].adjvex=v0;
			}  
	}
}
