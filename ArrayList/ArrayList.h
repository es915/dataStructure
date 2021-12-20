#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100

#include "NameCard.h"
typedef NameCard * LData;

typedef struct _ArrayList {
	LData arr[LIST_LEN]; // 리스트 저장소 
	int sizeOfData; // 저장된 데이터의 수 
	int curPosition; // 데이터 참조 위치 
} ArrayList;

typedef ArrayList List;

void ListInit(List * plist); // 리스트 초기화 
void LInsert(List * plist, LData data); // 데이터 삽입 

int LFirst(List * plist, LData * pdata); // 첫 데이터 
int LNext(List * plist, LData * pdata); // 두번째 데이터 부터 끝까지 

LData LRemove(List * plist); // 데이터 삭제 
int LCount(List * plist); // 데이서 수 구현 
#endif
