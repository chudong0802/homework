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