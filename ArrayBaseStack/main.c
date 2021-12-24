#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

int main(void) {
	Stack stack;

	StackInit(&stack);
	
	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	
	while(!SIsEmpty(&stack)) {
		printf("%d ", SPop(&stack));
	}
	
	return 0;
}
