#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

int main(void) {
	List list;
	ListInit(&list);
	int data;

	LInsert(&list, 6);
	LInsert(&list, 7);
	LInsert(&list, 8);
	LInsert(&list, 9);
	LInsert(&list, 10);
	
	LInsertFront(&list, 5);
	LInsertFront(&list, 4);
	LInsertFront(&list, 3);
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);
	
	// 데이터를 30회 연속으로 출력해주세요.
	// 원형 연결리스트는 마지막 데이터 다음 데이터로 다시 첫번째 데이터를 순회합니다.
	// LNext를 이용하여 30회 연속으로 출력해주세요. for문 또는 while문으로 이용 가능합니다.
	// 1, 2, 3, 4 .. 9, 10, 1, 2, 3, 4 ... 9, 10, 1, 2, 3, 4 ... 9, 10
	
	int i=1;
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		while(LNext(&list, &data)) {
			if(i<30) {
				printf("%d ", data);
			} else {
				break;
			}
			i++;
		}
	}
		
	printf("\n===데이터 삭제===\n");
	i=1;
	if(LFirst(&list, &data)) {
		if(data%2==0) {
			LRemove(&list);
		}
		
		while(LNext(&list, &data)) {
			if(i>=10) {
				break;
			} else {
				if(data%2==0) {
					LRemove(&list);
					
				}
			}
			i++;
		}
	}
	// 수정 필요 
	printf("===데이터 출력===\n");
	i=1;
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		while(LNext(&list, &data)) {
			if(i<LCount) {
				printf("%d ", data);
			} else {
				break;
			}
			i++;
		}
	}
	
	return 0;
}
