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
