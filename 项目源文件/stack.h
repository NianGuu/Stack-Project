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
int StackInsert(Army* army) {
	
}
