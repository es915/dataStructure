#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

// ���� �ʱ�ȭ 
void StackInit(Stack * pstack){
	pstack->topIndex = -1; 
}

// ���� ����ִ���
int SIsEmpty(Stack * pstack) {
	if(pstack->topIndex==-1) {
		return TRUE;
	}else {
		return FALSE;
	}
}

//���� �� á����
int SIsFull(Stack * pstack) {
	if(pstack->topIndex >= STACK_LEN-1) {
		return TRUE;
	} else {
		return FALSE;
	}
}

// ���� ������ �߰�
void SPush(Stack * pstack, Data data) {
	if(SIsFull(pstack)) {
		printf("Stack OverFlow!");
		exit(-1); // ���μ��� ����  
	}
	
	(pstack->topIndex)++;
	pstack->stackArr[pstack->topIndex] = data;
}

// ������ ����
Data SPop(Stack * pstack) {
	int rIdx;

	if(SIsEmpty(pstack)) {
		printf("Stack Empty!");
		exit(-1); // ���μ��� ���� 
	}
	
	rIdx = pstack->topIndex;
	(pstack->topIndex)--;
	
	return pstack->stackArr[rIdx];
}

// �ֻ�� ������ 
Data SPeek(Stack * pstack) {
	if(SIsEmpty(pstack)) {
		printf("Stack Empty!");
		exit(-1); // ���μ��� ���� 
	}
	
	return pstack->stackArr[pstack->topIndex];
}



















































