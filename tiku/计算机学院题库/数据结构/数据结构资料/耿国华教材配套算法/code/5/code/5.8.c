int Depth(GList L)
{ 
	int d, max;
	GLNode *s;
	if(L==NULL) 
		return(1);    /* �ձ����Ϊ1 */
	if(L->tag==ATOM) 
		return(0);    /* ԭ�����Ϊ0 */
	s=L;
	while(s!=NULL)    /* ��ÿ���ӱ����ȵ����ֵ */
	{ 
		d=Depth(s->atom_htp.htp.hp);
		if(d>max) max=d;
    		s=s->atom_htp.htp.tp;
   	}
	return(max+1);    /* �����ȵ��������ӱ����ȼ�1 */
}
