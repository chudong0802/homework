/*�ڽӱ�洢�ṹ����ʽ��˵�����£�*/

#define INFINITY 32768             /*��ʾ����ֵ������*/
#define True 1
#define False 0
#define Error -1
#define NULL 0
#define Ok 1
#define MAX_VERTEX_NUM 20             /*��ඥ�����*/
typedef enum{DG, DN, UDG, UDN} GraphKind;  /*ͼ������*/
typedef char VertexNode;

typedef struct ArcNode
{
	int adjvex;     /*�û�ָ�򶥵��λ��*/
    	struct ArcNode *nextarc;    /*ָ����һ������ָ��*/
    	OtherInfo info;       /*��û���ص���Ϣ*/
}ArcNode;

typedef struct VertexNode
{
	VertexData data;        /*��������*/
    	ArcNode *firstarc;    /*ָ��ö����һ������ָ��*/
}VertexNode;

typedef struct
{
    VertexNode vertex[MAX_VERTEX_NUM];   
    int vexnum,arcnum;               /*ͼ�Ķ������ͻ���*/
    GraphKind kind;                        /*ͼ�������־*/
}AdjList;           /*�����ڽӱ��ͼ(Adjacency List Graph)*/
