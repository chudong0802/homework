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

