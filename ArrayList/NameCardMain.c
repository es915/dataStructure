#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

//	***** MENU *****
//	1. Insert // �����͸� �߰�
//	2. Search // �����͸� �˻�, �̸��� �������� �˻�
//	3. Modify // �����͸� ����, �̸��� �������� ����
//	4. Delete // �����͸� ����, �̸��� �������� ����
//	5. Print All // ��� �����͸� ���
//	6. Count // ���� �������� ���� ��ȯ
//	7. Exit // �ܼ� ���α׷��� ����
//	
//	Choose the item: 1
//	[ INSERT ]
//	Choose the item: 2
//	[ SEARCH ]
//	Choose the item: 7
//	[ EXIT ]
//	���α׷��� �����մϴ�.

int main(void) {
	List list;
	LData nameCard;
	int item;
	char name[30], phone[30];
	
	ListInit(&list);
	
	while(1) {
		
		printf("***** MENU *****\n");
		printf("1. Insert\n");
		printf("2. Search\n");
		printf("3. Modify\n");
		printf("4. Delete\n");
		printf("5. Print All\n");
		printf("6. Count\n");
		printf("7. Exit\n");
	
		printf("Choose the item :");
		scanf("%d", &item);
		
		if(item==1) {
			printf("[ INSERT ]\n");
			
			printf("Input Name : ");
			scanf("%s", name);
			printf("Input Phone Number : ");
			scanf("%s", phone);
			
			nameCard = MakeNameCard(name, phone);
			LInsert(&list, nameCard);
			
			printf("Data Inserted\n");
			
		} else if(item==2) {
			printf("[ SEARCH ]\n");
			
			printf("Input Name : ");
			scanf("%s", name);
			
			int isNull = -1;
			
			if(LFirst(&list, &nameCard)) {
				if(!NameCompare(nameCard, name)) {
					ShowNameCardInfo(nameCard);
					isNull = 0;
				}
				while (LNext(&list, &nameCard)) {
					if(!NameCompare(nameCard, name)) {
						ShowNameCardInfo(nameCard);
						isNull = 0;
					}
				}
			}
			
			if(isNull==-1) {
				printf("���� ���� �ʴ� �̸��Դϴ�\n");
			} else {
				printf("Data Searched\n");
			} 
			
		} else if(item==3) {
			printf("[ MODIFY ]\n");
			
			printf("Input Name : ");
			scanf("%s", name);
			printf("Change Phone Number :");
			scanf("%s", phone);
			
			if(LFirst(&list, &nameCard)) {
				if(!NameCompare(nameCard, name)) {
					ChangePhoneNumber(nameCard, phone);
				}	
				while (LNext(&list, &nameCard)) {
					if(!NameCompare(nameCard, name)) {
						ChangePhoneNumber(nameCard, phone);
					}
				}
			}
			
		} else if(item==4) {
			printf("[ DELETE ]\n");
	
			printf("Input Name : ");
			scanf("%s", name);
			
			if(LFirst(&list, &nameCard)) {
				if(!NameCompare(nameCard, name)) {
					LRemove(&list);
					free(nameCard);
				}	
				while (LNext(&list, &nameCard)) {
					if(!NameCompare(nameCard, name)) {
						LRemove(&list);
						free(nameCard);
					}
				}
			}
			
		} else if(item==5) {
			printf("[ PRINT ALL ]\n");
			
			if(LFirst(&list, &nameCard)) {
				printf("Name : %s, Phone : %s\n", nameCard->name, nameCard->phone);
				while (LNext(&list, &nameCard)) {
					printf("Name : %s, Phone : %s\n", nameCard->name, nameCard->phone);
				}
			}
			
		} else if(item==6) {
			printf("[ COUNT ]\n");
			printf("Total Data Number : %d\n", LCount(&list));
		} else if(item==7) {
			printf("[ EXIT ]\n");
			break;
		} else {
			printf("�߸��� �Է�\n"); 
			break;
		}
		
	}
	
	
	return 0;
}
