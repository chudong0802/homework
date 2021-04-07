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
