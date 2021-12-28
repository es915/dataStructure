#include <stdio.h>
#include <stdlib.h>
#include "InfixToPostfix.h"

int main() {

	char exp1[] = "4+2*(5*8/3)";
	
	ConvToPostfix(exp1); // 후위표기법으로 변경 
	
	printf("%s \n", exp1);
	
	printf("%d \n", Caculate(exp1)); // 후위표기법으로 된 식 계산 
	
	return 0;
}
