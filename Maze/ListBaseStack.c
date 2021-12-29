#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack) {
	pstack->head == NULL;
}

int SIsEmpty(Stack * pstack) {
	if(pstack->head == NULL) {
		return TRUE;
	} else {
		return FALSE;
	}
}

void SPush(Stack * pstack, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = pstack->head;
	
	printf("[스택 추가 %d, %d] > ", data.x, data.y);
	pstack->head = newNode;
}

Data SPop(Stack * pstack) {
	Data rIdx;
	Node * rnode;
	
	if(SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}
	
	rIdx = pstack->head->data;
	rnode = pstack->head;
	
	pstack->head = rnode->next;
	
	printf("[스택 삭제 %d, %d] > ", rIdx.x, rIdx.y);
	
	free(rnode);
	
	return rIdx;
}

Data SPeek(Stack * pstack) {
	if(SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}
	
	return pstack->head->data;
}
