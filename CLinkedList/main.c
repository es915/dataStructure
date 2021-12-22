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
	
	// �����͸� 30ȸ �������� ������ּ���.
	// ���� ���Ḯ��Ʈ�� ������ ������ ���� �����ͷ� �ٽ� ù��° �����͸� ��ȸ�մϴ�.
	// LNext�� �̿��Ͽ� 30ȸ �������� ������ּ���. for�� �Ǵ� while������ �̿� �����մϴ�.
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
		
	printf("\n===������ ����===\n");
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
	// ���� �ʿ� 
	printf("===������ ���===\n");
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
