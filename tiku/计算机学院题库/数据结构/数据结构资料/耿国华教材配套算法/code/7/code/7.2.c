/*����һ������ͼ��ʮ��������㷨���£�*/

#include "OrthList.h"


void  CrtOrthList(OrthList *g)
/*���ն�����n���������Ϣ��e��������Ϣ���Խ���һ������ͼ��ʮ������*/
{
	int n,e;
	int i,j,k;
	char vt,vh;

	ArcNode *p;
	printf("�Ӽ�������ͼ�Ķ�������ͻ��ĸ���");
	fflush(stdin);
	scanf("%d,%d",&n,&e);  /*�Ӽ�������ͼ�Ķ�������ͻ��ĸ���*/
	g->vexnum = n;
	g->arcnum = e;
	for(i=0;i<n;i++) 
	{
		printf("����ͼ�Ķ���");
		fflush(stdin);
		scanf("%c",&g->vertex[i].data);
		g->vertex[i].firstin=NULL;g->vertex[i].firstout=NULL;
	}
	for(k=0;k<e;k++) 
	{
		printf("����һ��������������");
		fflush(stdin);
		scanf("%c,%c",&vt,&vh);
		i=LocateVertex(g,vt);
		j = LocateVertex(g,vh);
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->tailvex=i;
		p->headvex=j;
		p->tlink=g->vertex[i].firstout;
		g->vertex[i].firstout=p;
		p->hlink=g->vertex[j].firstin;
		g->vertex[j].firstin=p;
    }
}/* CrtOrthList */

void main()
{
	OrthList g;
	CrtOrthList(&g);
}