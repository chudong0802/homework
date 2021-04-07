/*ͼ��ʮ������ṹ��ʽ���������£�*/

#define MAX_VERTEX_NUM 20              /*��ඥ�����*/
#define INFINITY 32768             /*��ʾ����ֵ������*/
#define True 1
#define False 0
#define Error -1
#define Ok 1
typedef enum{DG, DN, UDG, UDN} GraphKind;  /*ͼ������*/
typedef char VertexData;    /*���趥������Ϊ�ַ���*/
typedef char VertexNode;    /*���趥������Ϊ�ַ���*/

typedef struct ArcNode 
{
	int tailvex,headvex;  
	struct ArcNode *hlink,*tlink;    
}ArcNode;

typedef struct VertexNode
{
	VertexData data;    /*������Ϣ*/
	ArcNode *firstin,*firstout;   
}VertexNode;

typedef struct
{
	VertexNode vertex[MAX_VERTEX_NUM];   
	int vexnum,arcnum;   /*ͼ�Ķ������ͻ���*/
	GraphKind kind;              /*ͼ������*/
}OrthList;      /*ͼ��ʮ�������ʾ��(Orthogonal List)*/
