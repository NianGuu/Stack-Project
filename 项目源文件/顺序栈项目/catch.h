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
