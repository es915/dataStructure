#include <stdio.h>
#include <stdlib.h>
#include "InfixToPostfix.h"

int main() {

	char exp1[] = "4+2*(5*8/3)";
	
	ConvToPostfix(exp1); // ����ǥ������� ���� 
	
	printf("%s \n", exp1);
	
	printf("%d \n", Caculate(exp1)); // ����ǥ������� �� �� ��� 
	
	return 0;
}
