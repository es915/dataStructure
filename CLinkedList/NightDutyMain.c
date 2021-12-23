#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

void ShowEmployeeInfo(Employee * emp);

Employee * WhosNightDay(List * plist, char * name, int day);

int main() {
	Employee * pemp;
	
	// 원형 연결리스트 
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
	
 	// 테리 근무 일 부터 15일 후에 근무자는 누구냐	
	pemp = WhosNightDay(&list, "Hary", 15);
	ShowEmployeeInfo(pemp);
	
	return 0;
}

Employee * WhosNightDay(List * plist, char * name, int day) {
	Employee * ret;
	int size = LCount(plist);
	int i;

	// ret에 처음 값 넣고 > Terry
	LFirst(plist, &ret);
	
	// 0이 아님 = 다르다 / ret->name != name 
	if(strcmp(ret->name, name) != 0) { // 참 
		for(i=0; i<size-1; i++) { // First를 뺸 값을 돌림 
			LNext(plist, &ret); // Next로 돌리다가 
			 
			if(strcmp(ret->name, name)==0) { // 맞으면 탈출> ret->name == name; 
				break;
			}
		}
	}
	
	for(i=0; i<day; i++) { // 원형 리스트로 Next 계속해도 계속 돌음 
		LNext(plist, &ret); // day만큼 옆으로 돌림 > 15일 후 == 15번 돌림 
	}
	
	return ret;
}

void ShowEmployeeInfo(Employee * emp) {
	printf("Employee name : %s\n", emp->name);
	printf("Employee empNum : %d\n", emp->empNum);
}

















