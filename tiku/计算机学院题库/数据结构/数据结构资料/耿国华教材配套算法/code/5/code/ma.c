/*�������A�д���������һ��Ԫ��A[i][j]��������:A[i][j]�ǵ�i����ֵ��С��Ԫ��,�����ǵ�j����ֵ����
Ԫ��,���֮Ϊ�þ����һ�����㡣��дһ�����������1��n�ľ���A���������㡣
�㷨˼�룺������,�����ÿ�е���СֵԪ��,����min[m]֮��,�����ÿ�е����ֵԪ��,����max[n]֮��,��ĳ
Ԫ�ؼ���min[i]��,����max[j]��,���Ԫ��A[i][j]��������,�ҳ�����������Ԫ��,���ҵ����������㡣���,
ʵ�ֱ��⹦�ܵĳ�������:*/
#include <stdio.h>
#define m 3
#define n 3

void minmax(int a[m][n])
{
	int i1,j,have=0;
	int min[m],max[n];
	for(i1=0;i1<m;i1++)/*�����ÿ�е���СֵԪ��,����min[m]֮��*/
	{
		min[i1]=a[i1][0];
		for(j=1;j<n;j++)
			if(a[i1][j]<min[i1]) min[i1]=a[i1][j];
	}
	for(j=0;j<n;j++)/*�����ÿ�е����ֵԪ��,����max[n]֮��*/
	{
		max[j]=a[0][j];
		for(i1=1;i1<m;i1++)
			if(a[i1][j]>max [j]) max[j]=a[i1][j];
	}
	for(i1=0;i1<m;i1++)
		for(j=0;j<n;j++)
			if(min[i1]==max[j])
			{
				printf("(%d,%d):%d\n",i1,j,a[i1][j]);
				have=1; 
			}
			if(!have) printf("û�а����n");
} 

void main()
{
	int a[m][n];
	int i,j; 
	printf("������һ������\n"); 
	for(i=0;i<m;i++) 
		for(j=0;j<n;j++) 
			scanf("%d",&a[i][j]); 
	minmax(a);
}
