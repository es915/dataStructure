#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "PostCaculator.h"

int Caculate(char exp[]) {
	Stack stack;
	StackInit(&stack);
	
	int expLen = strlen(exp);
	int i;
	char tok, op1, op2;
	for(i=0; i<expLen; i++) {
		tok = exp[i];
		
		if(isdigit(tok)) {
			SPush(&stack, tok-'0');
		} else {
			op2 = SPop(&stack);
			op1 = SPop(&stack);
			switch(tok){
				case '+':
					tok = op1 + op2;
					break;
				case '-':
					tok = op1 - op2;
					break;
				case '*':
					tok = op1 * op2;
					break;
				case '/':
					tok = op1 / op2;
					break;	
			}
			SPush(&stack, tok);
		}
	}
	
	return SPop(&stack);
}
