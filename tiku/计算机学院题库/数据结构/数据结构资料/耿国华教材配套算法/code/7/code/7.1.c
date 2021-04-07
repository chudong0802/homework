/*���ڽӾ��󷨴������������㷨���£�*/
#include "adjmatrix.h"

int LocateVertex(AdjMatrix *G,VertexData v)    /*�󶥵�λ�ú���*/
{
	int j=Error,k;
	for(k=0;k<G->vexnum;k++)
		if(G->vexs[k]==v)
		{ 
			j=k; 
			break; 
		}
	return(j);
}

int CreateDN(AdjMatrix *G)  /*����һ��������*/
{ 
	int i,j,k,weight; 
	VertexData v1,v2;
	printf("����ͼ�Ķ������ͻ���\n");
	fflush(stdin);
    scanf("%d,%d",&G->arcnum,&G->vexnum); /*����ͼ�Ķ������ͻ���*/
    for(i=0;i<G->vexnum;i++)       /*��ʼ���ڽӾ���*/
		for(j=0;j<G->vexnum;j++)
			G->arcs[i][j].adj=INFINITY;
    for(i=0;i<G->vexnum;i++)
	{
        printf("����ͼ�Ķ���\n");
		fflush(stdin);
		scanf("%c",&G->vexs[i]);  /* ����ͼ�Ķ���*/
	}
	for(k=0;k<G->arcnum;k++)
	{ 
		printf("����һ�������������㼰Ȩֵ\n");
		fflush(stdin);
		scanf("%c,%c,%d",&v1,&v2,&weight);/*����һ�������������㼰Ȩֵ*/
	  	i=LocateVertex(G,v1);
	    j=LocateVertex(G,v2); 
	    G->arcs[i][j].adj=weight;  /*������*/
	} 
	return(Ok);
}

void main()
{
	AdjMatrix G;
	CreateDN(&G);
}