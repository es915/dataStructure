#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

// 리스트 초기화 
void ListInit(List * plist) {
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

// 꼬리에 노드 추가
void LInsert(List * plist, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if(plist->tail == NULL) {
		plist->tail = newNode;
		newNode->next = newNode;
	} else {
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}
	
	(plist->numOfData)++;
}

// 머리에 노드 추가 
void LInsertFront(List * plist, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if(plist->tail == NULL) {
		plist->tail = newNode;
		newNode->next = newNode;
	} else {
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}

	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata) {
	if(plist->tail == NULL) {
		return FALSE;
	}	
	
	plist->before = plist->tail;
	plist->cur = plist->tail->next;
	
	*pdata = plist->cur->data;
	
	return TRUE;
} 

int LNext(List * plist, Data * pdata) {
	if(plist->tail == NULL) {
		return FALSE;
	}	
	
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	
	*pdata = plist->cur->data;
	
	return TRUE;
}

Data LRemove(List * plist) {
	Node * rpos = plist->cur;
	Data rdata = rpos->data;
	
	// 예외 1 - 삭제할 데이터가 마지막 위치면서 마지막 데이터일때 
	// 예외 2 - 삭제할 데이터가 마지막 위치라면..
	if(rpos == plist->tail) {
		if(plist->tail == plist->tail->next) {
			plist->tail == NULL;
		} else {
			plist->tail = plist->before;
		}
	}
	
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	
	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist) {
	return plist->numOfData;
}





















