#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

void ShowEmployeeInfo(Employee * emp);

Employee * WhosNightDay(List * plist, char * name, int day);

int main() {
	Employee * pemp;
	
	// ���� ���Ḯ��Ʈ 
	List list;
	ListInit(&list);
	
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 1;
	strcpy(pemp->name, "Terry");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 2;
	strcpy(pemp->name, "Jery");
	LInsert(&list, pemp);
	
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 3;
	strcpy(pemp->name, "Hary");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 4;
	strcpy(pemp->name, "Sunny");
	LInsert(&list, pemp);
	
 	// �׸� �ٹ� �� ���� 15�� �Ŀ� �ٹ��ڴ� ������	
	pemp = WhosNightDay(&list, "Hary", 15);
	ShowEmployeeInfo(pemp);
	
	return 0;
}

Employee * WhosNightDay(List * plist, char * name, int day) {
	Employee * ret;
	int size = LCount(plist);
	int i;

	// ret�� ó�� �� �ְ� > Terry
	LFirst(plist, &ret);
	
	// 0�� �ƴ� = �ٸ��� / ret->name != name 
	if(strcmp(ret->name, name) != 0) { // �� 
		for(i=0; i<size-1; i++) { // First�� �A ���� ���� 
			LNext(plist, &ret); // Next�� �����ٰ� 
			 
			if(strcmp(ret->name, name)==0) { // ������ Ż��> ret->name == name; 
				break;
			}
		}
	}
	
	for(i=0; i<day; i++) { // ���� ����Ʈ�� Next ����ص� ��� ���� 
		LNext(plist, &ret); // day��ŭ ������ ���� > 15�� �� == 15�� ���� 
	}
	
	return ret;
}

void ShowEmployeeInfo(Employee * emp) {
	printf("Employee name : %s\n", emp->name);
	printf("Employee empNum : %d\n", emp->empNum);
}

















