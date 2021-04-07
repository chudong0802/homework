int pre[];
void one_path(Graph *G, int u, int v)
/*����ͨͼG����һ���ӵ�u�����㵽v������ļ�·��*/
{
	int i;
    	pre=(int *)malloc(G->vexnum*sizeof(int));
    	for(i=0;i<G->vexnum;i++) 
    		pre[i]=-1;
    	pre[u]=u;               /*��pre[u]��Ϊ��-1����ʾ��u�������ѱ�����*/
    	DFS_path(G, u, v);       /*���������������һ����u��v�ļ�·����*/
    	free(pre);
}

Void DFS_path(Graph *G, int u, int v)
  /*����ͨͼG���������������������һ����u��v�ļ�·����*/
{
	int j;
     	if(pre[v]!=-1)
        	for(j=firstadj(G,u);j>=0;j=nextadj(G,u,j))
             		if(pre[j]==-1)
			{
                  		pre[j]=u;
                  		if(j==v) 
                  			print_path(pre ,v); /*���·��*/
                  		else 
                  			DFS_path(G,j,v); 
              		}
}
