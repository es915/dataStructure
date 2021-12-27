#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "InfixToPostfix.h"

int GetOpPrec(char op) {
	switch(op) { // 우선순위 부여 / 숫자 높음 = 우선순위 높음 
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

// 우선순위 비교 
int WhoPrecOp(char op1, char op2) {
	int op1Prec = GetOpPrec(op1); // 우선순위 저장 
	int op2Prec = GetOpPrec(op2); // 우선순위 저장 
	
	if(op1Prec > op2Prec) {
		return 1; // 스택에 최상단에 위치한 연산자의 우선순위가 높다면? 꺼내서 배열 뒤에 삽입
	} else if(op1Prec < op2Prec) {
		return -1; // 스택에 최상단에 위치한 연산자의 우선순위가 낮다면? 스택에 쌓음
	} else {
		return 0; // 스택에 최상단에 위치한 연산자의 우선순위가 높다면? 꺼내서 배열 뒤에 삽입
	}
}

void ConvToPostfix(char exp[]) {
	Stack stack; // 스택 생성 
	StackInit(&stack); // 스택 초기화 
	
	int expLen = strlen(exp); 
	char * convExp = (char*)malloc(expLen + 1);
	
	memset(convExp, 0, sizeof(char) * expLen+1);
	
	int i, idx=0;
	char tok, popOp;
	for(i=0; i<expLen; i++) {
		tok = exp[i]; // 체크할 문자 하나
		
		// include ctype - isdigit()
		if(isdigit(tok)) { // 숫자 = true 문자 = false 
			convExp[idx++] = tok; // 숫자면 배열에 넣음
			// tok이 들어가고 ++ 됨 
		} else {
			switch(tok) {
				case '(' : // 가장 낮은 우선순위 = 맨 밑에 깔림
					SPush(&stack, tok); //stack 에 tok를 넣음
					break;
				case ')' :
					while(1) {
						popOp = SPop(&stack);
						if(popOp == '(') { // 여는 소괄호를 발견할때까지 팝  
							break;
						}
						convExp[idx++] = popOp; // 팝 한 값을 배열에 삽입 
					} 
					break;
				case '+' : 
				case '-' :
				case '*' :
				case '/' :
					// 비어있지 않고 최상단스택(op1)과 tok(op2)을 비교 
					while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0) { // 자리를 잡을때까지 여러번에 체크를 해야 하므로 while 
						convExp[idx++] = SPop(&stack); // op1가 높으면(1 or 0 반환) 스택에서 팝 -> 배열 추가 
					}
					
					SPush(&stack, tok); // tok 스택 추가 
					break;
			}
		}
	}
	
	while(!SIsEmpty(&stack)) { // 우선순위가 밀려 남아있는 연산자를 모두 팝 
		convExp[idx++] = SPop(&stack);
	}
	
	strcpy(exp, convExp);
	free(convExp);
}


































