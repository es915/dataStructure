#include <stdio.h>
#include <stdlib.h>
#include "InfixToPostfix.h"

int main() {

	char exp1[] = "(9+2/5-(5-3*5))";
	
	ConvToPostfix(exp1);
	
	printf("%s \n", exp1);
	
	return 0;
}
