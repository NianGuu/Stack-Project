/*Ӣ��˳���*/
typedef struct {
	Hero hero[heroNum];
	int length;
}HeroList;

/*��ʼ����*/
void InitList(HeroList* list) {
	list->length = 0;
}
/*���*/
int ListLength(HeroList list) {
	return list.length;
}
/*������*/
int ListFull(HeroList list) {
	if (list.length == heroNum - 1)
		return TRUE;
	return FALSE;
}
/*�пձ�*/
int ListEmpty(HeroList list) {
	if (list.length == 0)
		return TRUE;
	return FALSE;
}
/*����*/
int ListInsert(HeroList* list, int i, Hero hero) {
	if (ListFull(*list))
		return FALSE;
	int j;
	for ( j = ListLength(*list);j <= i;j++)
		list->hero[j + 1] = list->hero[j];
	list->hero[j] = hero;
	list->length++;
	return TRUE;
}