int visited[MAX_VERTEX_NUM];   /*���ʱ�־����*/

void TraverseGraph(Graph g)
/*��ͼg�����������������Graph ��ʾͼ��һ�ִ洢�ṹ���������ʾ�����ڽӱ��*/
{
	for(vi=0;vi<g.vexnum;vi++)  
		visited[vi]=False ;/*���ʱ�־�����ʼ*/
	for(vi=0;vi<g.vexnum;vi++)	/*������ȱ�����ͨ��ͼ�Ĳ���*/
		if (!visited[vi])  
			DepthFirstSearch(g,vi);	/*��ͼg����ͨͼ�����ѭ�����ú���ִֻ��һ��*/
}/* TraverseGraph */
