
/*��ʼ������*/
void InitArrtibute(Attribute* attribute) {
	attribute->ATK = 100;			//��ʼ��������
	attribute->DEF = 10;			//��ʼ��������
	attribute->HP = 1000;			//��ʼ��Ѫ��
	attribute->gold = 0;			//��ʼ�����
}

/*��ʼ��Ӣ��*/
void InitHero(Hero* hero, int i, char name[nameLength]) {
	hero->army.ID = i;					//��ʼ�� ID
	hero->army.top = -1;				//��ʼ������
	InitArrtibute(&hero->attribute);	//��ʼ������
	strcpy_s(hero->name, name);			//��ʼ������
}

