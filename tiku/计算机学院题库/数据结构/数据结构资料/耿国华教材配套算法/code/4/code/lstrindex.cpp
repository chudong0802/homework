#include "stdio.h"
#include "stdlib.h"

/*��ʽ�洢��ʽ�µ�ģʽƥ�䣬ÿ���ַ���һ����ʾ*/

typedef struct Block{
	char   ch;
	struct Block   *next;
}Block;

typedef struct {
	Block   *head;
	Block   *tail;
	int     len;
}BLString;

int StrAssign(BLString *s, char *tval)
/*���ַ�������tval��ֵ����������s*/
{
	Block *p,*q;
	int len, i=0;

	if (s->head != NULL) {
		/*�ͷ�ԭ���洢��S�еĽ��ռ�*/
		p = s->head;
		while (p != NULL) {
			q = p->next;
			free(p);
			p = q;
		}

		s->head = s->tail = NULL;
	}

	/*�����ַ�������*/
	while (tval[i] != '\0') i++;

	len = i;s->len = len;

	if (len > 0) {
		p = (Block *)malloc(sizeof(Block));
		if (p == NULL) return 1;
		s->head = s->tail = q = p;
		i=0;

		while (i < len) {
			p = (Block *)malloc(sizeof(Block));
			if (p == NULL) return 1;
			q->next = p;q = p;

			//printf("\nCopying %c",tval[i]);
			p->ch = tval[i++];
		}
	}

	q->next = NULL;s->tail = q;

	return 0;
}

int StrDelete(BLString *s, int pos, int len)
{
	/*�ڴ�s��ɾ�����±�pos��len���ַ� */
	int i,j;
	Block *p,*q,*r;

	if (pos<0 || pos>(s->len - len)) return 1;

	i = 0;
	p = s->head;
	while(i<pos){
		p = p->next;
		i++;
	}

	q = p;

	j = 0;
	p = p->next;
	while (j<len) {
		r = p->next;
		//printf("\ndeleting %c",p->ch);
		free(p);
		p = r;
		j++;
	}

	q->next = p;
	s->len = s->len - len;
	if (q->next == NULL) {
		s->tail = q;
	}

	return 0;
}

Block *StrIndex(BLString *s, BLString *t)
/*���Ӵ�t������s�е�һ�γ��ֵ�λ��ָ��*/
{
	Block *p = NULL;
	Block *q = NULL;
	Block *tmp = NULL;
	int j;

	if (t->len == 0) return NULL;

	p = s->head->next;
	q = t->head->next;
	tmp = p;
	j = 0;
	while(p != NULL && q != NULL)
	{
		if (p->ch == q->ch) {
			p = p->next;
			q = q->next;
		}
		else
		{
			p = tmp->next;
			tmp = p;
			j++;
			q = t->head->next;
		}
	}

	if ( q == NULL) {
		printf("\nFound!=%c in position %d\n",tmp->ch,j);
		return tmp;
	}
	else return NULL;
}

int main()
{
	static BLString s,t;
	char str1[80],str2[80];

	printf("����������s�����ݣ�");
	scanf("%s",str1);
	printf("\n�������Ӵ�t�����ݣ�");
	scanf("%s",str2);

	StrAssign(&s,str1);
	StrAssign(&t,str2);

	Block *pos = StrIndex(&s,&t);
	if (pos == NULL) {
		printf("\nString not found!\n");
	}

	//�ͷſռ�
	StrDelete(&s,0,s.len);
	StrDelete(&t,0,t.len);
	return 0;
}