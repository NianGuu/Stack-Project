#include "define.h"
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

/*����*/
typedef struct {
	int ID;							//�������
	Dogface dogface[armyLength];	//С��
	int top;						//ջ��
}Army;

/*Ӣ��*/
typedef struct {
	Attribute attruibute;			//����
	Army army;						//����
	char name[nameLength];			//����
}Hero;