/*��ȡС������*/
Attribute catchAttribute(int i) {
	/*�����б�*/
	/*����ֵ���������������������*/
	Attribute aError = { -1,-1,-1,-1 };
	Attribute a0 = { 0,0,0,0 };
	Attribute a1 = { 100,10,10,10 };
	Attribute a2 = { 200,10,10,10 };
	Attribute a3 = { 200,20,20 ,20 };
	/*��������*/
	switch (i) {
	case 0:return a0;
	case 1:return a1;
	case 2:return a2;
	case 3:return a3;
	default:return aError;
	}
}
/*��ȡС��*/
Dogface catchDogface(int i) {
	/*С���б�*/
	/*���ԣ�ID���̵�۸�*/
	Dogface dError = { catchAttribute(-1),-1,-1 };
	Dogface d0 = { catchAttribute(0),0,0 };
	Dogface d1 = { catchAttribute(1),1,100 };
	Dogface d2 = { catchAttribute(2),2,200 };
	Dogface d3 = { catchAttribute(3),3,300 };
	/*����С��*/
	switch (i) {
	case 0:return d0;
	case 1:return d1;
	case 2:return d2;
	case 3:return d3;
	default:return dError;
	}
}
/*��ȡӢ��*/
Hero catchHero(int i) {
	/*Ӣ���б�*/
	/*Ӣ��ID������ID�����֣��̵�۸�*/
	Hero hError = { -1,-1,ERROR,-1 };
	Hero h0 = { 0,0,"NULL",0 };
	Hero h1 = { 1,1,"����",100 };
	Hero h2 = { 2,2,"��������",200 };
	Hero h3 = { 3,3,"���ռ�ū",300 };
	/*����Ӣ��*/
	switch (i) {
	case 0:return h0;
	case 1:return h1;
	case 2:return h2;
	case 3:return h3;
	default:return hError;
	}
}