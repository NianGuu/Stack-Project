/*��ʼ�����*/
Player InitPlayer(char name[nameLength]) {
	Player player;
	player.gold = 0;
	strcpy_s(player.name, name);
	return player;
}

/*��ʼ������*/
void InitArrtibute(Attribute* attribute) {
	attribute->ATK = 100;			//��ʼ��������
	attribute->DEF = 10;			//��ʼ��������
	attribute->HP = 1000;			//��ʼ��Ѫ��
	attribute->gold = 0;			//��ʼ�����
}
