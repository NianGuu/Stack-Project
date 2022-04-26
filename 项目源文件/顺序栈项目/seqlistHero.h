Hero catchHero(int);

/*��ʼ����*/
void InitHero(HeroList* list) {
	list->length = 0;
}
/*���*/
int HeroLength(HeroList list) {
	return list.length;
}
/*������*/
int HeroFull(HeroList list) {
	if (list.length == heroNum)
		return TRUE;
	return FALSE;
}
/*�пձ�*/
int HeroEmpty(HeroList list) {
	if (list.length == 0)
		return TRUE;
	return FALSE;
}
/*����*/
int HeroInsert(HeroList* list, int i, Hero hero) {
	if (HeroFull(*list))
		return FALSE;
	int j;
	for (j = HeroLength(*list)-1;j > i-1;j--)
		list->hero[j+1] = list->hero[j];
	list->hero[i] = hero;
	list->length++;
	return TRUE;
}

/*����*/
void HeroSeq(HeroList* list) {
	if (HeroEmpty(*list))
		return;
	Hero temp;
	for (int i = 0;i < list->length;i++)
		for (int j = i + 1;j < list->length;j++) {
			if (list->hero[j].ID < list->hero[i].ID) {
				temp = list->hero[i];
				list->hero[i] = list->hero[j];
				list->hero[j] = temp;
			}
			if (list->hero[i].ID==0) {
				temp = list->hero[i];
				list->hero[i] = list->hero[j];
				list->hero[j] = temp;
			}
		}
}
/*ɾ��*/
Hero HeroDelete(HeroList* list, int i) {
	Hero out = list->hero[i - 1];
	list->hero[i - 1] = catchHero(0);
	HeroSeq(list);
	list->length--;
	return out;
}
/*��ñ���*/
int getHero(Player* player, int i) {
	if (i > HeroLength(player->unHero))
		return FALSE;
	HeroInsert(&player->ownHero, 0, HeroDelete(&player->unHero, i));
	HeroSeq(&player->ownHero);
	return TRUE;
}