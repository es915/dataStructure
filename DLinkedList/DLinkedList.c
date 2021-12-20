#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node)); // 새 더미 노드를 생성 
	plist->head->next = NULL;
	plist->comp = NULL; // 비교 함수 수행 전 
	plist->numOfData = 0;
}

void FInsert(List * plist, LData data) // head와 newNode 사이에 데이터 삽입 
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = plist->head->next;
	plist->head->next = newNode;
	
	(plist->numOfData)++;
}

void SInsert(List * plist, LData data) // head와 newNode 사이에 데이터 삽입 
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	Node * pred = plist->head; // pred는 데이터를 삽입하는 위치를 정하는 주소값입니다. 
	newNode->data = data;
	
	// 새 노드가 들어갈 위치를 찾는 반복문입니다.
	// 비교값이 0이면 종료 
	while(pred->next != NULL && plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}
	
	newNode->next = pred->next;
	pred->next = newNode;
	
	(plist->numOfData)++;
}

void LInsert(List * plist, LData data)
{
	if(plist->comp == NULL) // 정렬 기준이 없다면 맨 앞부터 데이터 저장합니다. 
	{
		FInsert(plist, data);	
	}
	else {
		SInsert(plist, data);
	}
}

int LFirst(List * plist, LData * pdata)
{
	if(plist->head->next == NULL)
	{
		return FALSE;
	}
	
	plist->before = plist->head;
	plist->cur = plist->head->next; // head의 next가 첫번째 값 
	
	*pdata = plist->cur->data; // 첫번째 노드의 데이터를 전달
	return TRUE; 
}

int LNext(List * plist, LData * pdata)
{
	if(plist->cur->next == NULL)
	{
		return FALSE;
	}
	
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	
	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List * plist)
{
	Node * rpos = plist->cur; // 삭제할 주소값 
	LData rdata = rpos->data; // 삭제할 주소의 데이터
	
	plist->before->next = plist->cur->next; // 이 한줄로 삭제 로직 구현 가능합니다.
	plist->cur = plist->before; // 위치 재조정
	
	free(rpos);
	(plist->numOfData)--;
	return rdata; 
}

int LCount(List * plist)
{
	return plist->numOfData;
}

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = comp; // 정렬 기준을 등록합니다. main에서 plist는 한개만 존재합니다. 
}
