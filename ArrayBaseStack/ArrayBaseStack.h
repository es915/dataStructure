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

// ���� �ʱ�ȭ 
void StackInit(Stack * pstack);

// ���� ����ִ���
int SIsEmpty(Stack * pstack);

//���� �� á����
int SIsFull(Stack * pstack);

// ���� ������ �߰�
void SPush(Stack * pstack, Data data);

// ������ ����
Data SPop(Stack * pstack);

// �ֻ�� ������ 
Data SPeek(Stack * pstack);
 
#endif

