#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "PostCaculator.h"

int Caculate(char exp[]) {
	Stack stack; // 스택 생성
	StackInit(&stack); // 스택 초기화
	
	int expLen = strlen(exp); // exp의 글자수를 expLen에 담음
	int i;
	char tok, op1, op2;
	for(i=0; i<expLen; i++) { // 글자 수만큼 반복
		tok = exp[i]; // 글자 하나식 tok에 넣음
		
		if(isdigit(tok)) { // tok이 숫자인지 문자(연산자)인지 체크
			SPush(&stack, tok-'0'); // 숫자면 스택에 푸쉬, -'0' = 문자열을 정수형으로 변경
		} else {
			op2 = SPop(&stack); // 연산자를 만나면 2번째 피연산자를 먼저 뽑음
			op1 = SPop(&stack); // 그다음 1번째 피연산자를 뽑음
			switch(tok){
				case '+': 
					tok = op1 + op2; // 1번째 피연산자와 2번째 피연산자를 연산자에 맞게 계산
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
			SPush(&stack, tok); // 계산을 종료하여 tok에 담아둔 값을 다시 스택에 넣음
		}
	}
	
	return SPop(&stack); // 계산을 모두 끝맞치고 스택에 남은 피연산자, 최종값을 팝하여 보여줌
}
