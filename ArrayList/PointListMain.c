#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

int PointListMain(void) {
	
//	- main.c 파일을 만들어서 작업합니다.
//	- Point 구조체를 만들어 순차 리스트를 초기화합니다.
//	- [3, 1], [3, 2], [4, 1], [4, 2] 과 같은 4개의 데이터 저장합니다.
//	- 저장된 데이터를 출력합니다.
//	- xpos가 4인 데이터를 모두 삭제합니다. (삭제하기 위해 xpos는 4 ypos 0으로 데이터를 초기화합니다.)
//	- 두 포인터 변수를 비교한 뒤 일치하는 값을 찾아 삭제합니다.
//	- 삭제 후 남은 데이터를 출력합니다.
//	- 유의사항 : ArrayList에서 LData 값은 Point에 맞게 교체해줘야 합니다.
	
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
	
	printf("=== 현재 저장된 데이터 출력 ===\n");
	
	if(LFirst(&list, &ppos)) {
		ShowPointPos(ppos);
		
		while(LNext(&list, &ppos)) {
			ShowPointPos(ppos);	
		}
	}
	
	printf("=== xpos가 4인 데이터 모두 삭제 ===\n\n");
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
	
	printf("=== 현재 저장된 데이터 출력 ===\n");
	
	if(LFirst(&list, &ppos)) {
		
		ShowPointPos(ppos);
		
		while(LNext(&list, &ppos)) {
			ShowPointPos(ppos);	
		}
	}
	
	
	
//	=== 현재 저장된 데이터 출력 ===
//	[3, 1]
//	[3, 2]
//	[4, 1]
//	[4, 2]
//	
//	=== xpos가 4인 데이터 모두 삭제 ===
//	
//	=== 현재 저장된 데이터 출력 ===
//	[3, 1]
//	[3, 2]
	
	
	return 0;
}
