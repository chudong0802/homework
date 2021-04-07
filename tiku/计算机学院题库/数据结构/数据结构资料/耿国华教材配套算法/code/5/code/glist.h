#include <malloc.h>
/*������ͷβ����洢�ṹ���Ͷ������£�*/
typedef enum {ATOM, LIST} ElemTag;  /* ATOM��0����ʾԭ�ӣ�LIST��1����ʾ�ӱ�*/
typedef struct GLNode
{   
	ElemTag tag;             /*��־λtag��������ԭ�ӽ��ͱ���*/
	union
	{ 
		AtomType atom;                 /*ԭ�ӽ���ֵ��atom*/
		struct 
		{ 
			struct GLNode *hp,*tp;
		}htp;   /*�����ָ����htp,������ͷָ����hp�ͱ�βָ����tp*/
	}atom_htp;  /* atom_htp ��ԭ�ӽ���ֵ��atom�ͱ����ָ����htp����������*/
}GLNode,*GList;

/*������ı�ͷ*/

GList Head(GList L)
{
	if(L==NULL) 
		return(NULL);    /* �ձ��ޱ�ͷ */
	if(L->tag==ATOM) 
		exit(0);    /* ԭ�Ӳ��Ǳ� */
	else 
		return(L->atom_htp.htp.hp);
}

/*������ı�β*/

GList Tail(GList L)
{
	if(L==NULL) 
		return(NULL);    /* �ձ��ޱ�β */
	if(L->tag==ATOM) 
		exit(0);    /* ԭ�Ӳ��Ǳ�*/
	else 
		return(L->atom_htp.htp.tp);
}

/*������ĳ���*/

int Length(GList L)
{ 
	int n=0;
	GLNode *s;
	if(L==NULL) 
		return(0);    /* �ձ���Ϊ0 */
	if(L->tag==ATOM) 
		exit(0);    /* ԭ�Ӳ��Ǳ� */
	s=L;
	while(s!=NULL)    /* ͳ�����ϲ��ĳ��� */
	{ 
		k++;
		s=s->atom_htp.htp.tp;
	}
	return(k);
}

/*����������*/

int Depth(GList L)
{ 
	int d,max;
	GLNode *s;
	if(L==NULL) 
		return(1);    /* �ձ����Ϊ1 */
	if(L->tag==ATOM) 
		return(0);    /* ԭ�����Ϊ0 */
	s=L;
	while(s!=NULL)    /* ��ÿ���ӱ����ȵ����ֵ */
	{ 
		d=Depth(s->atom_htp.htp.hp);
		if(d>max) 
			max=d;
		s=s->atom_htp.htp.tp;
	}
	return(max+1);    /* �����ȵ��������ӱ����ȼ�1 */
}

/*ͳ�ƹ������ԭ����Ŀ����һ*/

int CountAtom1(GList L)
{ 
	int n;
	GLNode *s;
	if(L==NULL) 
		return(0);    /* �ձ���û��ԭ�� */
	if(L->tag==ATOM) 
		return(1);    /* Lָ�򵥸�ԭ�� */
	s=L; 
	n=0;
	while(s!=NULL)    /* ��ÿ���ӱ��ԭ����Ŀ֮�� */
	{ 
		n=n+CountAtom(s->atom_htp.htp.hp);
		s=s->atom_htp.htp.tp;
	}
	return(n);
}

/*ͳ�ƹ������ԭ����Ŀ������*/

int CountAtom2(GList L)
{ 
	int n1, n2;
	if(L==NULL) 
		return(0);    /* �ձ���û��ԭ�� */
	if(L->tag==ATOM) 
		return(1);    /* Lָ�򵥸�ԭ�� */
	n1=CountAtom(L->atom_htp.htp.hp);    /* ���ͷ�е�ԭ����Ŀ */
	n2=CountAtom(L->atom_htp.htp.tp);    /* ���β�е�ԭ����Ŀ */
	return(n1+n2);
}

/*���ƹ����*/
int CopyGList(GList S, GList *T)
{ 
	if(S==NULL) 
	{ 
		*T=NULL; 
		return(OK); 
	}    /* ���ƿձ� */
	*T=(GLNode *)malloc(sizeof(GLNode));
	if(*T==NULL) 
		return(ERROR);
	(*T)->tag=S->tag;
	if(S->tag==ATOM) 
		(*T)->atom=S->atom;    /* ���Ƶ���ԭ�� */
	else
	{
		CopyGList(S->atom_htp.htp.hp, &((*T)->atom_htp.htp.hp));    /* ���Ʊ�ͷ */
		CopyGList(S->atom_htp.htp.tp, &((*T)->atom_htp.htp.tp));    /* ���Ʊ�β */
	}
	return(OK);
}
