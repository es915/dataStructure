#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "InfixToPostfix.h"

int GetOpPrec(char op) {
	switch(op) { // �켱���� �ο� / ���� ���� = �켱���� ���� 
		case '*':
		case '/':
			return 5;
		case '+':
		case '-':
			return 3;
		case '(':
			return 1;
	}
	return -1;
}

// �켱���� �� 
int WhoPrecOp(char op1, char op2) {
	int op1Prec = GetOpPrec(op1); // �켱���� ���� 
	int op2Prec = GetOpPrec(op2); // �켱���� ���� 
	
	if(op1Prec > op2Prec) {
		return 1; // ���ÿ� �ֻ�ܿ� ��ġ�� �������� �켱������ ���ٸ�? ������ �迭 �ڿ� ����
	} else if(op1Prec < op2Prec) {
		return -1; // ���ÿ� �ֻ�ܿ� ��ġ�� �������� �켱������ ���ٸ�? ���ÿ� ����
	} else {
		return 0; // ���ÿ� �ֻ�ܿ� ��ġ�� �������� �켱������ ���ٸ�? ������ �迭 �ڿ� ����
	}
}

void ConvToPostfix(char exp[]) {
	Stack stack; // ���� ���� 
	StackInit(&stack); // ���� �ʱ�ȭ 
	
	int expLen = strlen(exp); 
	char * convExp = (char*)malloc(expLen + 1);
	
	memset(convExp, 0, sizeof(char) * expLen+1);
	
	int i, idx=0;
	char tok, popOp;
	for(i=0; i<expLen; i++) {
		tok = exp[i]; // üũ�� ���� �ϳ�
		
		// include ctype - isdigit()
		if(isdigit(tok)) { // ���� = true ���� = false 
			convExp[idx++] = tok; // ���ڸ� �迭�� ����
			// tok�� ���� ++ �� 
		} else {
			switch(tok) {
				case '(' : // ���� ���� �켱���� = �� �ؿ� ��
					SPush(&stack, tok); //stack �� tok�� ����
					break;
				case ')' :
					while(1) {
						popOp = SPop(&stack);
						if(popOp == '(') { // ���� �Ұ�ȣ�� �߰��Ҷ����� ��  
							break;
						}
						convExp[idx++] = popOp; // �� �� ���� �迭�� ���� 
					} 
					break;
				case '+' : 
				case '-' :
				case '*' :
				case '/' :
					// ������� �ʰ� �ֻ�ܽ���(op1)�� tok(op2)�� �� 
					while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0) { // �ڸ��� ���������� �������� üũ�� �ؾ� �ϹǷ� while 
						convExp[idx++] = SPop(&stack); // op1�� ������(1 or 0 ��ȯ) ���ÿ��� �� -> �迭 �߰� 
					}
					
					SPush(&stack, tok); // tok ���� �߰� 
					break;
			}
		}
	}
	
	while(!SIsEmpty(&stack)) { // �켱������ �з� �����ִ� �����ڸ� ��� �� 
		convExp[idx++] = SPop(&stack);
	}
	
	strcpy(exp, convExp);
	free(convExp);
}


































