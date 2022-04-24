#include<stdio.h>
#include<Windows.h>
#include<string.h>

#include "define.h"


void SetCursor(int);				//���ù��
void JumpCursor(short, short);		//��ת�����ָ��λ��

void InitFrame();					//��ʼ����Ϸ�߿�

void Ready(Hero* hero);				//��ʼ����

void Menu(Hero hero);				//�˵�����

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
void Ready(Hero* hero) {
	char name[nameLength];
	InitFrame();
	printf("\33[%d;%dH��ӭ������Ϸ", 12, 50);
	printf("\33[%d;%dH�������������", 13, 49);
	SetCursor(TRUE);
	JumpCursor(14, 52);
	gets_s(name);
	strcpy_s(hero->name, name);
}

/*�˵�����*/
void Menu(Hero hero) {
	InitFrame();
	printf("\33[%d;%dH������ʿ��%s", 5, 20, hero.name);
	printf("\33[%d;%dH��ӵ�еĽ�ң�%d", 6, 20, hero.attribute.gold);
	getchar();
}

/*��ʼ����Ϸ�߿�*/
void InitFrame() {
	system("CLS");
	int color1 = 30;		//�߿�ǰ��ɫ(��Χ30-37)
	int color2 = 43;		//�߿��ɫ����Χ40-47��
	for (int i = 1;i < COL;i++)
		for (int j = 1;j <= ROW;j++) {
			if (i == 1 || i == COL - 1)
				printf("\33[%dm\33[%dm\33[%d;%dH%s\33[0m", color1, color2, j, i, TOP);
			else
				if (j == 1 || j == ROW)
					printf("\33[%dm\33[%dm\33[%d;%dH%s\33[0m", color1, color2, j, i, SIDE);
		}
}

