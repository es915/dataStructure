#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

int main() {
	List list;
	ListInit(&list);
	int data;
	
	LInsert(&list, 8);
	LInsert(&list, 7);
	LInsert(&list, 6);
	LInsert(&list, 5);
	LInsert(&list, 4);
	LInsert(&list, 3);
	LInsert(&list, 2);
	LInsert(&list, 1);
	
	if(LFirst(&list, &data)){
		printf("%d ", data);
		while(LNext(&list, &data)) {
			printf("%d ", data);	
		}
	}
	int n = 0;
	if(LFirst(&list, &data)){
		printf("%d ", data);
		while(LNext(&list, &data)) {
			if(n==3) {
				break;
			}
			printf("%d ", data);
			n++;
		}
		printf("<-");
		while(LPrevious(&list, &data)) {
			printf("%d ", data);
		}
	}
	
	return 0;
}
