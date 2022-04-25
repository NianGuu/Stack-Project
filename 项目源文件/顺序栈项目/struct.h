/*ʵ������*/
typedef struct {
	int HP;			//����ֵ
	int ATK;		//������
	int DEF;		//������
	int gold;		//���
}Attribute;

/*С��*/
typedef struct {
	Attribute attribute;	//����
	int ID;					//ID
	int diamond;			//�̵�۸�
}Dogface;

/*Ӣ��*/
typedef struct {
	int	ID;							//Ӣ��ID
	int IDskill;					//����ID
	char name[nameLength];			//����
	int diamond;					//�̵�۸�
}Hero;

/*Ӣ��˳���*/
typedef struct {
	Hero hero[heroNum];
	int length;
}HeroList;

/*����˳���*/
typedef struct {
	Dogface dogface[dogfaceNum];
	int length;
}DogfaceList;

/*���*/
typedef struct {
	char name[nameLength];			//�������
	int diamond;					//�����ʯ
	HeroList ownHero;				//����Ӣ��
	HeroList unHero;				//δ��Ӣ��
	DogfaceList ownDogface;			//���б���
	DogfaceList unDogface;			//δ�б���
}Player;