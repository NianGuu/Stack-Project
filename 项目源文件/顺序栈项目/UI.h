#include "entity.h"
#include "shop.h"
#include "fight.h"

Player InitPlayer(char name[nameLength]);		//��ʼ�����

void SetCursor(int);							//���ù��
void JumpCursor(short, short);					//��ת�����ָ��λ��
void InitFrame();								//��ʼ����Ϸ�߿�
Player Ready();									//��ʼ����
void Menu(Player*);								//�˵�����
void Error();									//�������
	
/*�˵�����*/
void Menu(Player* player) {
	int x = 15;				//�˵�λ��
	int y = 52;				//�˵�λ��
	int distance = 3;		//�˵����
	char choose;			//�û�ѡ��
head:
	InitFrame();
	printf("\33[36m\33[%d;%dH���ĳ�����%s", 5, 10, player->name);
	printf("\33[%d;%dH��ӵ�е���ʯ��%d", 6, 10, player->diamond);
	printf("\33[36m\33[%d;%dH��ѡ����Ҫ��ʲô", 10, 49);
	printf("\33[34m\33[%d;%dH����������������������������\33[0m", 11, 43);
	printf("\33[36m\33[%d;%dH������1-3\33[0m", 12, 52);
	printf("\33[36m\33[%d;%dHo��������o", x - 1, y);
	printf("\33[%d;%dH|  ս��  |", x, y);
	printf("\33[%d;%dH*��������*", x + 1, y);
	printf("\33[%d;%dHo��������o", x + distance - 1, y);
	printf("\33[%d;%dH|  �̵�  |", x + distance, y);
	printf("\33[%d;%dH*��������*", x + distance + 1, y);
	printf("\33[%d;%dHo��������o", x + distance * 2 - 1, y);
	printf("\33[%d;%dH|  �˳�  |", x + distance * 2, y);
	printf("\33[%d;%dH*��������*", x + distance * 2 + 1, y);
	choose = _getch();
	switch (choose) {
	case '1':FightMenu(player);goto head;
	case '2':ShopMenu(player);goto head;
	case '3':return;
	default:Error();goto head;
	}
}

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
	int x = ROW / 2 - 3;
	int y = 46;
	printf("\33[31m\33[%d;%dH*��������������������*", x, y);
	printf("\33[%d;%dH|��������������������|", x + 1, y);
	printf("\33[%d;%dH|����������ȷ��ѡ�|", x + 2, y);
	printf("\33[%d;%dH|��������������������|", x + 3, y);
	printf("\33[%d;%dH*��������������������*", x + 4, y);
	_getch();
}