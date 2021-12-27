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

// 부여된 우선순위를 비교함
int WhoPrecOp(char op1, char op2) {
	int op1Prec = GetOpPrec(op1); // 최상단 스택
	int op2Prec = GetOpPrec(op2); // 비교할 연산자
	
	if(op1Prec > op2Prec) {
		return 1; // 최상단 스택이 우선순위가 높다면, 최상단 스택을 팝시켜 배열에 삽입 시킴
	} else if(op1Prec < op2Prec) {
		return -1; // 최상단 스택이 우선순위가 낮다면 비교할 연산자를 스택에 넣음
	} else {
		return 0; // 최상단 스택이 더 크다면, 최상단 스택을 팝시켜 배열에 삽입 시킴
	}
}

void ConvToPostfix(char exp[]) {
	Stack stack; // 스택 생성 
	StackInit(&stack); // 스택 초기화 
	
	int expLen = strlen(exp); // exp의 글자수를 저장함, 문자열은 맨 뒤에 0이 붙지만 strlen은 0을 제외함
	char * convExp = (char*)malloc(expLen + 1); // expLen + 1 -> strlen이 제외한 맨 뒷자리(0)를 한칸 생성해줌
	
	// convExp의 값을 0으로 초기화, convExp의 사이즈는 문자열로 글자수+1 (0 자리 마련)
	memset(convExp, 0, sizeof(char) * expLen + 1); 
	
	int i, idx=0;
	char tok, popOp;
	for(i=0; i<expLen; i++) {
		tok = exp[i]; // 체크할 문자 하나를 tok에 넣음
		
		// include ctype - isdigit()
		if(isdigit(tok)) { // 숫자 = true 문자 = false 
			convExp[idx++] = tok; // tok이 숫자면 배열에 넣어라
			// tok이 들어가고 ++ 됨 
		} else {
			switch(tok) {
				case '(' : // 가장 낮은 우선순위 = 맨 밑에 깔림
					SPush(&stack, tok); // stack 에 tok를 넣음
					break;
				case ')' :
					while(1) {
						popOp = SPop(&stack);
						if(popOp == '(') { // 여는 소괄호를 발견할때까지 팝  
							break; // 여는 소괄호 발견시 while 종료 -> case break
						}
						convExp[idx++] = popOp; // 팝 한 값을 배열에 삽입 
					} 
					break;
				case '+' : 
				case '-' :
				case '*' :
				case '/' :
					// 비어있지 않고 SPeek로 뽑은 최상단스택(op1)과 tok(op2)을 비교 
					while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0) { // 자리를 잡을때까지 여러번에 체크를 해야 하므로 while 
									// 0보다 크다 -> 우선순위가 최상단 스택의 우선순위가 높거나 같은경우 일때 실행
						convExp[idx++] = SPop(&stack); // op1가 높으니 스택에서 팝 -> 배열 추가 
					}
					
					SPush(&stack, tok); // tok 스택 추가 
					break;
			}
		}
	}
	
	while(!SIsEmpty(&stack)) { // 우선순위가 낮아 스택안에 남아있는 연산자들을 팝
		convExp[idx++] = SPop(&stack);
	}
	
	// string + copy = strcpy - 문자열 복사
	strcpy(exp, convExp); // convExp의 문자열을 exp에 복사
	free(convExp); // 복사했기에 필요없는 convExp 메모리 삭제
}


































