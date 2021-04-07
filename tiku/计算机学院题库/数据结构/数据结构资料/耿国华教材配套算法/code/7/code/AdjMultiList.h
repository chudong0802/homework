#define MAX_VERTEX_NUM 20              /*��ඥ�����*/
#define INFINITY 32768             /*��ʾ����ֵ������*/
#define True 1
#define False 0
#define Error -1
#define Ok 1
typedef enum{DG, DN, UDG, UDN} GraphKind;  /*ͼ������*/
typedef char VertexNode;    /*���趥������Ϊ�ַ���*/
typedef struct EdgeNode 
{
	int mark,ivex,jvex;
	struct EdgeNode *ilink,*jlink;
}EdgeNode;

typedef struct 
{
    	VertexData data;
    	EdgeNode *firstedge;
}VertexNode;

typedef struct
{
    	VertexNode vertex[MAX_VERTEX_NUM];   
    	int vexnum,arcnum;           /*ͼ�Ķ������ͻ���*/
    	GraphKind kind;                     /*ͼ������*/
}AdjMultiList;         /*����ͼ���ڽӶ��ر��ʾ��(Adjacency Multi_list)*/
