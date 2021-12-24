#ifndef __AB_STACK_H__
#define __AB_STACK_H__

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef int Data;

typedef struct _arrayStack{
	Data stackArr[STACK_LEN];
	int topIndex;
}ArrayStack;

typedef ArrayStack Stack;

// 스택 초기화 
void StackInit(Stack * pstack);

// 스택 비어있는지
int SIsEmpty(Stack * pstack);

//스택 꽉 찼는지
int SIsFull(Stack * pstack);

// 스택 데이터 추가
void SPush(Stack * pstack, Data data);

// 데이터 삭제
Data SPop(Stack * pstack);

// 최상단 데이터 
Data SPeek(Stack * pstack);
 
#endif

