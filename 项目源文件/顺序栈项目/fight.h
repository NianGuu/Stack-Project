void InitFrame();

void FightMenu(Player* player) {
	while (1) {
		InitFrame();
		printf("\33[%d;%dH����һ���ǳ�ţ�Ƶ�ս�����棡", 10, 45);
		_getch();
	}
}
