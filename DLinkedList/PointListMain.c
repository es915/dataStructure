#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"

int PostListMain(void)
{
	List list; // 사용할 리스트 
	Point comPos; // 비교할 때 사용 
	Point * ppos; // 데이터 CRUD시 사용 
	
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
	
	// 저장된 데이터 출력
	printf("=== 현재 저장된 데이터 출력 ===\n");
	
	if(LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);	
		
		while(LNext(&list, &ppos)) {
			ShowPointPos(ppos);
		}
	}
	
	printf("\n");
	
	// xpos가 2인 데이터 삭제
	comPos.xpos = 2;
	comPos.ypos = 0;
	
	// xpos가 2인 데이터 모두 삭제
	printf("=== xpos가 2인 데이터 모두 삭제 ===\n");
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
	// 저장된 데이터 출력
	printf("=== 현재 저장된 데이터 출력 ===\n");
	
	if(LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);	
		
		while(LNext(&list, &ppos)) {
			ShowPointPos(ppos);
		}
	}
	
	return 0;
}
