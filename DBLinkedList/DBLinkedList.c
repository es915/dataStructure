#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List * plist) {
	plist->head = NULL;
	plist->numOfData = 0;
}

void LInsert(List * plist, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = plist->head;
	
	if(plist->head!=NULL) {
		plist->head->prev = newNode;		
	}
	
	newNode->prev = NULL;
	plist->head = newNode;
}

int LFirst(List * plist, Data * pdata){
	if(plist->head==NULL) {
		return FALSE;
	}	
	
	plist->cur = plist->head;
	*pdata = plist->cur->data;
	
	return TRUE;
}

int LNext(List * plist, Data * pdata) {
	if(plist->next == NULL) {
		return FALSE;
	}
	
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	
	return TRUE;
}

int LPrevioust(List * plist, Data * pdata) {
	if(plist->prev == NULL) {
		return FALSE;
	}
	
	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;
	
	return TRUE;
}

int LCount(List * plist) {
	return plist->numOfData;
}





