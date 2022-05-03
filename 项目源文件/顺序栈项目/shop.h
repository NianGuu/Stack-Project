void ShopDogface(Player* player);
void ShopHero(Player* player);
int getDogface(Player*, int);
int getHero(Player*, int);

void NoMoney() {
	int x = ROW / 2 - 3;
	int y = 46;
	printf("\33[31m\33[%d;%dH*——————————*", x, y);
	printf("\33[%d;%dH|！！！！！！！！！！|", x + 1, y);
	printf("\33[%d;%dH|！！！你钱不够！！！|", x + 2, y);
	printf("\33[%d;%dH|！！！！！！！！！！|", x + 3, y);
	printf("\33[%d;%dH*——————————*", x + 4, y);
	_getch();
}
void ShopMenu(Player* player) {
	char choosech;
	int choose;
	int x = 6;
	int y = 10;
	while (1) {
		InitFrame();
		printf("\33[36m\33[%d;%dH钻石：%d", x - 1, y, player->diamond);
		printf("\33[36m\33[%d;%dH请选择你要买什么(Esc退出)", x + 1, y);
		printf("\33[36m\33[%d;%dH1.兵种", x + 10, y * 5);
		printf("\33[36m\33[%d;%dH2.英雄", x + 15, y * 5);
		choosech = _getch();
		if (choosech == 27)
			return;
		if (choosech == '1')
			ShopDogface(player);
		else if (choosech == '2')
			ShopHero(player);
		else
			Error();
	}
}

void ShopDogface(Player* player) {
	if (player->unDogface.length == 0) {
		int x = ROW / 2 - 3;
		int y = 46;
		printf("\33[31m\33[%d;%dH*——————————*", x, y);
		printf("\33[%d;%dH|！！！！！！！！！！|", x + 1, y);
		printf("\33[%d;%dH|！！你已经买完了！！|", x + 2, y);
		printf("\33[%d;%dH|！！！！！！！！！！|", x + 3, y);
		printf("\33[%d;%dH*——————————*", x + 4, y);
	}
	char choose;
	while (1) {
		InitFrame();
		printf("\33[36m\33[%d;%dH钻石：%d", 5, 10, player->diamond);
		printf("\33[36m\33[%d;%dH输入0确认购买，Esc退出", 7, 10);
		printf("\33[36m\33[%d;%dH名称：%-10s\t价格：%-10d", 20, 40, player->unDogface.dogface[0].name, player->unDogface.dogface[0].diamond);
		choose = _getch();
		if (choose == 27)
			return;
		if (choose == '0')
			if (player->diamond < player->unDogface.dogface->diamond)
				NoMoney();
			else {
				player->diamond -= player->unDogface.dogface->diamond;
				getDogface(player, 1);
			}
	}
}
void ShopHero(Player* player) {
	if (player->unHero.length == 0) {
		int x = ROW / 2 - 3;
		int y = 46;
		printf("\33[31m\33[%d;%dH*——————————*", x, y);
		printf("\33[%d;%dH|！！！！！！！！！！|", x + 1, y);
		printf("\33[%d;%dH|！！你已经买完了！！|", x + 2, y);
		printf("\33[%d;%dH|！！！！！！！！！！|", x + 3, y);
		printf("\33[%d;%dH*——————————*", x + 4, y);
	}
	char choose;
	while (1) {
		InitFrame();
		printf("\33[36m\33[%d;%dH钻石：%d", 5, 10, player->diamond);
		printf("\33[36m\33[%d;%dH输入0确认购买，Esc退出", 7, 10);
		printf("\33[36m\33[%d;%dH名称：%-10s\t价格：%-10d", 20, 40, player->unHero.hero[0].name, player->unHero.hero[0].diamond);
		choose = _getch();
		if (choose == 27)
			return;
		if (choose == '0')
			if (player->diamond < player->unHero.hero->diamond)
				NoMoney();
			else {
				player->diamond -= player->unHero.hero->diamond;
				getHero(player, 1);
			}
	}
}
