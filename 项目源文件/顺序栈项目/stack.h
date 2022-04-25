/*�з�����*/
typedef struct {
	Dogface dogface[armyLength];	//С��
	int top;						//ջ��
}Army;

/*��ʼ��ջ*/
void InitStack(Army* army) {
	army->top = -1;
}
/*��ջ��*/
int StackLength(Army army) {
	return army.top + 1;
}
/*����ջ*/
int StackFull(Army army) {
	if (army.top == armyLength - 1)
		return TRUE;
	return FALSE;
}
/*�п�ջ*/
int StackEmpty(Army army) {
	if (army.top == -1)
		return TRUE;
	return FALSE;
}
/*��ջ*/
int StackPush(Army* army,Dogface dogface) {
	if (StackFull(*army))
		return FALSE;
	army->top++;
	army->dogface[army->top] = dogface;
	return TRUE;
}
/*��ջ*/
int StackPop(Army* army, Dogface* dogface) {
	if (StackEmpty(*army))
		return FALSE;
	*dogface = army->dogface[army->top];
	army->top--;
	return TRUE;
}
