int CountAtom(GList L)
{ /*������L��ԭ�ӽ����Ŀ��������ԭ�ӽ����Ŀֵ*/
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
