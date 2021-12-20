#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

int PointListMain(void) {
	
//	- main.c ������ ���� �۾��մϴ�.
//	- Point ����ü�� ����� ���� ����Ʈ�� �ʱ�ȭ�մϴ�.
//	- [3, 1], [3, 2], [4, 1], [4, 2] �� ���� 4���� ������ �����մϴ�.
//	- ����� �����͸� ����մϴ�.
//	- xpos�� 4�� �����͸� ��� �����մϴ�. (�����ϱ� ���� xpos�� 4 ypos 0���� �����͸� �ʱ�ȭ�մϴ�.)
//	- �� ������ ������ ���� �� ��ġ�ϴ� ���� ã�� �����մϴ�.
//	- ���� �� ���� �����͸� ����մϴ�.
//	- ���ǻ��� : ArrayList���� LData ���� Point�� �°� ��ü����� �մϴ�.
	
	List list;
	Point comPos;
	Point * ppos;
	
	ListInit(&list);
	
	ppos=(Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);
	
	ppos=(Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);
	
	ppos=(Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 4, 1);
	LInsert(&list, ppos);
	
	ppos=(Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 4, 2);
	LInsert(&list, ppos);
	
	printf("=== ���� ����� ������ ��� ===\n");
	
	if(LFirst(&list, &ppos)) {
		ShowPointPos(ppos);
		
		while(LNext(&list, &ppos)) {
			ShowPointPos(ppos);	
		}
	}
	
	printf("=== xpos�� 4�� ������ ��� ���� ===\n\n");
	comPos.xpos = 4;
	comPos.ypos = 0;
	
	if(LFirst(&list, &ppos)) {
		if(PointComp(ppos, &comPos)==1) {
			ppos=LRemove(&list);
			free(ppos);
		}
		
		while(LNext(&list, &ppos)) {
			if(PointComp(ppos, &comPos)==1) {
				ppos=LRemove(&list);
				free(ppos);
			}
		}
	}
	
	printf("=== ���� ����� ������ ��� ===\n");
	
	if(LFirst(&list, &ppos)) {
		
		ShowPointPos(ppos);
		
		while(LNext(&list, &ppos)) {
			ShowPointPos(ppos);	
		}
	}
	
	
	
//	=== ���� ����� ������ ��� ===
//	[3, 1]
//	[3, 2]
//	[4, 1]
//	[4, 2]
//	
//	=== xpos�� 4�� ������ ��� ���� ===
//	
//	=== ���� ����� ������ ��� ===
//	[3, 1]
//	[3, 2]
	
	
	return 0;
}
