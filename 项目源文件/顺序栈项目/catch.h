/*��ȡС������*/
Attribute catchAttribute(int i) {
	/*�����б�*/
	Attribute aError = {-1,-1,-1,-1};
	Attribute a1 = { 100,10,10,10 };
	/*��������*/
	switch (i) {
	case 1:return a1;
	default:return aError;
	}
}
/*��ȡС��*/
Dogface catchDogface(int i) {
	/*С���б�*/
	Dogface dError = { catchAttribute(-1),-1,-1 };
	Dogface d1 = { catchAttribute(1),1,10 };
	/*����С��*/
	switch (i) {
	case 1:return d1;
	default:return dError;
	}
}
/*��ȡӢ��*/
Hero catchHero(int i) {
	/*Ӣ���б�*/
	Hero hError = {-1,-1,ERROR,-1};
	Hero h1 = { 1,1,"����",100};
	Hero h2 = { 2,2,"��������",200 };
	Hero h3 = {3,3,"���ռ�ū",300};
	/*����Ӣ��*/
	switch (i) {
	case 1:return h1;
	case 2:return h2;
	case 3:return h3;
	default:return hError;
	}
}