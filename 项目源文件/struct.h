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
	int type;				//����
}Dogface;

/*Ӣ��*/
typedef struct {
	int	ID;							//Ӣ��ID
	char name[nameLength];			//����
}Hero;

/*���*/
typedef struct {
	char name[nameLength];			//�������
	int gold;						//��ҽ��

}Player;