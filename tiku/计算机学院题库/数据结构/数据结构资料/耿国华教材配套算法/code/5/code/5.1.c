/*���þ���������洢��ʽ����ά���飩ʵ�־���ת�ã�*/
void TransMatrix(ElementType source[m][n],ElementType dest[n][m])
{
	/*Source��dest�ֱ�Ϊ��ת�õľ����ת���Ժ�ľ����ö�ά�����ʾ��*/
	int i,j;
	for(i=0;i<m;i++)
		for (j=0;j<n;j++)
			dest[j][i]=source[i][j];
}
