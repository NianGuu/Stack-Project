#include "entity.h"
#include "shop.h"
#include "fight.h"
void SetCursor(int);				//���ù��
void JumpCursor(short, short);		//��ת�����ָ��λ��

void InitFrame();					//��ʼ����Ϸ�߿�

Player Ready();				//��ʼ����

void Menu(Player*);					//�˵�����

void Error();						//�������

/*���ù��*/
/*����FALSE�����ع��*/
/*����TRUE����ʾ���*/
void SetCursor(int i) {
	CONSOLE_CURSOR_INFO cursor{ 1,i };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}
/*��ת�����ָ������*/
/*xΪ�ڼ��У�yΪ�ڼ��У���1��ʼ*/
void JumpCursor(short y, short x) {
	COORD pos = { x - 1,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/*��ʼ����*/
Player Ready() {
	char name[nameLength];
	InitFrame();
	printf("\33[%d;%dH��ӭ������Ϸ", 12, 50);
	printf("\33[%d;%dH�������������", 13, 49);
	SetCursor(TRUE);
	JumpCursor(14, 52);
	gets_s(name);
	Player player = InitPlayer(name);
	SetCursor(FLASE);
	return player;
}

/*��ʼ����Ϸ�߿�*/
void InitFrame() {
	system("CLS");
	int color1 = 30;		//�߿�ǰ��ɫ(��Χ30-37)
	int color2 = 43;		//�߿��ɫ����Χ40-47��
	char top[3] = "��";		//���±߿����
	char side[3] = "||";	//���ұ߿����
	for (int i = 1;i < COL;i++)
		for (int j = 1;j <= ROW;j++) {
			if (i == 1 || i == COL - 1)
				printf("\33[%dm\33[%dm\33[%d;%dH%s\33[0m", color1, color2, j, i, side);
			else
				if (j == 1 || j == ROW)
					printf("\33[%dm\33[%dm\33[%d;%dH%s\33[0m", color1, color2, j, i, top);
		}
}

/*�������*/
void Error() {
	int x=ROW/2-3;
	int y=46;
	printf("\33[31m\33[%d;%dH*��������������������*",x,y);
	printf("\33[%d;%dH|��������������������|",x+1,y);
	printf("\33[%d;%dH|����������ȷ��ѡ�|",x+2,y);
	printf("\33[%d;%dH|��������������������|",x+3,y);
	printf("\33[%d;%dH*��������������������*", x+4, y);
}