int CountAtom(GList L)
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
