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
