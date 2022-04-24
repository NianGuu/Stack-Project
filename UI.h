#include<stdio.h>
#include<Windows.h>

#include "define.h"
#include "struct.h"
void SetCursor(int );
void JumpCursor(short, short);
void Ready(Hero* hero);
void InitFrame();

/*���ù��*/
/*����FALSE�����ع��*/
/*����TRUE����ʾ���*/
void SetCursor(int i) {
	CONSOLE_CURSOR_INFO cursor{ 1,i };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}
/*��ת�����ָ������*/
void JumpCursor(short y, short x) {
	COORD pos = { x-1,y-1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/*��ʼ����*/
void Ready(Hero* hero) {
	InitFrame();
	printf("\33[%d;%dH��ӭ������Ϸ", 10, 50);
	printf("\33[%d;%dH�������������", 11, 49);
	SetCursor(TRUE);
	JumpCursor(1,52);

	getchar();
}
/*��ʼ����Ϸ�߿�*/
void InitFrame() {
	system("CLS");
	for (int i = 0;i < COL;i++)
		for (int j = 0;j <= ROW;j++) {
			if (i == 0 || i == COL - 1)
				printf("\33[%d;%dH%s", j, i, FRAME);
			else
				if (j == 0 || j == ROW)
					printf("\33[%d;%dH%s", j, i, FRAME);
		}
}

