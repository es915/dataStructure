#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "InfixToPostfix.h"

void ConvToPostfix(char exp[]) {
	Stack stack;
	StackInit(&stack);
	
	int expLen = strlen(exp);
	char * convExp = (char*)malloc(expLen + 1);
	
	memset(convExp, 0, sizeof(char) * expLen+1);
	
	int i;
	for(i=0; i<expLen; i++) {
		
	}
}
