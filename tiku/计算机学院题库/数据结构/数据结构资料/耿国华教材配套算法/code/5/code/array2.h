#define MAXSIZE 1000  /*����Ԫ�صĸ������Ϊ1000*/
#define ElementType int
/*ϡ�������Ԫ�������Ͷ���*/	
typedef struct
{   
	int row,col;  /*�÷���Ԫ�ص����±�����±�*/
    ElementType e; /*�÷���Ԫ�ص�ֵ*/
}Triple;

typedef struct
{  
	Triple data[MAXSIZE+1];   /* ����Ԫ�ص���Ԫ���data[0]δ��*/
	int m,n,len;          /*����������������ͷ���Ԫ�صĸ���*/
}TSMatrix;

/*����ת�õľ����㷨*/

/*"����"����ת�÷�*/

void TransposeTSMatrix(TSMatrix A,TSMatrix *B)
{ /*�Ѿ���Aת�õ�B��ָ��ľ�����ȥ����������Ԫ����ʾ*/
	int i,j,k;
	B->m=A.n; 
	B->n=A.m; 
	B->len=A.len;
	if(B->len>0)
	{
		j=1;				/*jΪ��������������¼ת�ú����Ԫ������Ԫ���B�е��±�ֵ*/
		for(k=1; k<=A.n; k++) /*ɨ����Ԫ���A ��k�Σ�ÿ��Ѱ����ֵΪk����Ԫ�����ת��*/
			for(i=1; i<=A.len; i++)
				if(A.data[i].col==k)
				{
					B->data[j].row=A.data[i].col;/*��ͷ��βɨ����Ԫ���A,Ѱ��colֵΪk����Ԫ�����ת��*/
					B->data[j].col=A.data[i].row;
					B->data[j].e=A.data[i].e;
					j++;		/*������j�Լӣ�ָ����һ�����ת�ú���Ԫ����±�*/
				}/*��ѭ����if�Ľ���*/
	}/* if(B->len>0)�Ľ���*/
}/* end of TransposeTSMatrix */

/*"��λ����ת��"��*/

void FastTransposeTSMatrix(TSMatrix A,TSMatrix *B)
{ 
	/*���ھ������Ԫ���ʾ������"��λ����ת��"����������Aת��Ϊ����B*/
	int col,t,p,q;
	int num[MAXSIZE], position[MAXSIZE];
	B->len=A.len; 
	B->n=A.m; 
	B->m=A.n;
	if(B->len)
	{
		for(col=1;col<=A.n;col++)
			num[col]=0;  
		for(t=1;t<=A.len;t++)
			num[A.data[t].col]++; /*����ÿһ�еķ���Ԫ�صĸ���*/	
		position[1]=1;
		for(col=2;col<=A.n;col++)  /*��col���е�һ������Ԫ����B.data[ ]�е���ȷλ��*/
			position[col]=position[col-1]+num[col-1]; 
		for(p=1;p<=A.len;p++)/*����ת�þ������Ԫ���A��ͷ��βɨ��һ�Σ�ʵ�־���ת��*/
		{  
			col=A.data[p].col;  
			q=position[col];
			B->data[q].row=A.data[p].col;
			B->data[q].col=A.data[p].row;
			B->data[q].e=A.data[p].e;
			position[col]++;/* position[col]��1��ָ����һ���к�Ϊcol�ķ���Ԫ������Ԫ���B�е��±�ֵ*/
		}/*end of for*/
	}
}
