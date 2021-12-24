#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

// 스택 초기화 
void StackInit(Stack * pstack){
	pstack->topIndex = -1; 
}

// 스택 비어있는지
int SIsEmpty(Stack * pstack) {
	if(pstack->topIndex==-1) {
		return TRUE;
	}else {
		return FALSE;
	}
}

//스택 꽉 찼는지
int SIsFull(Stack * pstack) {
	if(pstack->topIndex >= STACK_LEN-1) {
		return TRUE;
	} else {
		return FALSE;
	}
}

// 스택 데이터 추가
void SPush(Stack * pstack, Data data) {
	if(SIsFull(pstack)) {
		printf("Stack OverFlow!");
		exit(-1); // 프로세스 종료  
	}
	
	(pstack->topIndex)++;
	pstack->stackArr[pstack->topIndex] = data;
}

// 데이터 삭제
Data SPop(Stack * pstack) {
	int rIdx;

	if(SIsEmpty(pstack)) {
		printf("Stack Empty!");
		exit(-1); // 프로세스 종료 
	}
	
	rIdx = pstack->topIndex;
	(pstack->topIndex)--;
	
	return pstack->stackArr[rIdx];
}

// 최상단 데이터 
Data SPeek(Stack * pstack) {
	if(SIsEmpty(pstack)) {
		printf("Stack Empty!");
		exit(-1); // 프로세스 종료 
	}
	
	return pstack->stackArr[pstack->topIndex];
}



















































