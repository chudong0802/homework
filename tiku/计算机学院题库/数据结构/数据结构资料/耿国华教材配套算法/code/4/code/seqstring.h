
#define MAXLEN 40
typedef struct {          /*���ṹ����*/
    char ch[MAXLEN];
    int len;
}SString;

void createstring(SString *s)
{
	int i,j;
	char c;
	printf("������Ҫ�����Ĵ��ĳ���:");
	scanf("%d",&j);
	for(i=0; i<j; i++)
	{
		printf("�����봮�ĵ�%d���ַ�:",i+1);
		fflush(stdin);
		scanf("%c",&c);
		s->ch[i] = c;
	}
	s->len = j;
}

void output(SString *s)
{
	int i;
	for (i=0;i<s->len;i++)
		printf("%c   ",s->ch[i]);
	printf("\n");
}