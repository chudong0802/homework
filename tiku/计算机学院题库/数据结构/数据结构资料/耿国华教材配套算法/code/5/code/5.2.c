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