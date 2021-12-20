#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"

int PostListMain(void)
{
	List list; // ����� ����Ʈ 
	Point comPos; // ���� �� ��� 
	Point * ppos; // ������ CRUD�� ��� 
	
	ListInit(&list);
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);
	
	// ����� ������ ���
	printf("=== ���� ����� ������ ��� ===\n");
	
	if(LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);	
		
		while(LNext(&list, &ppos)) {
			ShowPointPos(ppos);
		}
	}
	
	printf("\n");
	
	// xpos�� 2�� ������ ����
	comPos.xpos = 2;
	comPos.ypos = 0;
	
	// xpos�� 2�� ������ ��� ����
	printf("=== xpos�� 2�� ������ ��� ���� ===\n");
	if(LFirst(&list, &ppos))
	{
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
	
	printf("\n");
	// ����� ������ ���
	printf("=== ���� ����� ������ ��� ===\n");
	
	if(LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);	
		
		while(LNext(&list, &ppos)) {
			ShowPointPos(ppos);
		}
	}
	
	return 0;
}
