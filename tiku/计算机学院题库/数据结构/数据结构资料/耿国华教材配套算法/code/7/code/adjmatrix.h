#define MAX_VERTEX_NUM 20             /*��ඥ�����*/
#define INFINITY 32768             /*��ʾ����ֵ������*/
#define True 1
#define False 0
#define Error -1
#define Ok 1

typedef enum{DG, DN, UDG, UDN} GraphKind;  /*ͼ�����ࣺDG��ʾ����ͼ, DN��ʾ������, UDG��ʾ����ͼ, UDN��ʾ������*/
typedef char VertexData;    /*���趥������Ϊ�ַ���*/

typedef struct ArcNode
{
	AdjType adj;   /*������Ȩͼ����1��0��ʾ�Ƿ����ڣ��Դ�Ȩͼ����ΪȨֵ����*/
	OtherInfo info;
}ArcNode;

typedef struct
{
	VertexData vexs[MAX_VERTEX_NUM];                        /*��������*/
	ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];   /*�ڽӾ���*/
	int vexnum,arcnum;          /*ͼ�Ķ������ͻ���*/
	GraphKind kind;                 /*ͼ�������־*/
}AdjMatrix;      /*(Adjacency Matrix Graph)*/


