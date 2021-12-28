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

// �ο��� �켱������ ����
int WhoPrecOp(char op1, char op2) {
	int op1Prec = GetOpPrec(op1); // �ֻ�� ����
	int op2Prec = GetOpPrec(op2); // ���� ������
	
	if(op1Prec > op2Prec) {
		return 1; // �ֻ�� ������ �켱������ ���ٸ�, �ֻ�� ������ �˽��� �迭�� ���� ��Ŵ
	} else if(op1Prec < op2Prec) {
		return -1; // �ֻ�� ������ �켱������ ���ٸ� ���� �����ڸ� ���ÿ� ����
	} else {
		return 0; // �ֻ�� ������ �� ũ�ٸ�, �ֻ�� ������ �˽��� �迭�� ���� ��Ŵ
	}
}

void ConvToPostfix(char exp[]) {
	Stack stack; // ���� ���� 
	StackInit(&stack); // ���� �ʱ�ȭ 
	
	int expLen = strlen(exp); // exp�� ���ڼ��� ������, ���ڿ��� �� �ڿ� 0�� ������ strlen�� 0�� ������
	char * convExp = (char*)malloc(expLen + 1); // expLen + 1 -> strlen�� ������ �� ���ڸ�(0)�� ��ĭ ��������
	
	// convExp�� ���� 0���� �ʱ�ȭ, convExp�� ������� ���ڿ��� ���ڼ�+1 (0 �ڸ� ����)
	memset(convExp, 0, sizeof(char) * expLen + 1); 
	
	int i, idx=0;
	char tok, popOp;
	for(i=0; i<expLen; i++) {
		tok = exp[i]; // üũ�� ���� �ϳ��� tok�� ����
		
		// include ctype - isdigit()
		if(isdigit(tok)) { // ���� = true ���� = false 
			convExp[idx++] = tok; // tok�� ���ڸ� �迭�� �־��
			// tok�� ���� ++ �� 
		} else {
			switch(tok) {
				case '(' : // ���� ���� �켱���� = �� �ؿ� ��
					SPush(&stack, tok); // stack �� tok�� ����
					break;
				case ')' :
					while(1) {
						popOp = SPop(&stack);
						if(popOp == '(') { // ���� �Ұ�ȣ�� �߰��Ҷ����� ��  
							break; // ���� �Ұ�ȣ �߽߰� while ���� -> case break
						}
						convExp[idx++] = popOp; // �� �� ���� �迭�� ���� 
					} 
					break;
				case '+' : 
				case '-' :
				case '*' :
				case '/' :
					// ������� �ʰ� SPeek�� ���� �ֻ�ܽ���(op1)�� tok(op2)�� �� 
					while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0) { // �ڸ��� ���������� �������� üũ�� �ؾ� �ϹǷ� while 
									// 0���� ũ�� -> �켱������ �ֻ�� ������ �켱������ ���ų� ������� �϶� ����
						convExp[idx++] = SPop(&stack); // op1�� ������ ���ÿ��� �� -> �迭 �߰� 
					}
					
					SPush(&stack, tok); // tok ���� �߰� 
					break;
			}
		}
	}
	
	while(!SIsEmpty(&stack)) { // �켱������ ���� ���þȿ� �����ִ� �����ڵ��� ��
		convExp[idx++] = SPop(&stack);
	}
	
	// string + copy = strcpy - ���ڿ� ����
	strcpy(exp, convExp); // convExp�� ���ڿ��� exp�� ����
	free(convExp); // �����߱⿡ �ʿ���� convExp �޸� ����
}



