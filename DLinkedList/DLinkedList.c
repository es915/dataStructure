#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node)); // �� ���� ��带 ���� 
	plist->head->next = NULL;
	plist->comp = NULL; // �� �Լ� ���� �� 
	plist->numOfData = 0;
}

void FInsert(List * plist, LData data) // head�� newNode ���̿� ������ ���� 
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = plist->head->next;
	plist->head->next = newNode;
	
	(plist->numOfData)++;
}

void SInsert(List * plist, LData data) // head�� newNode ���̿� ������ ���� 
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	Node * pred = plist->head; // pred�� �����͸� �����ϴ� ��ġ�� ���ϴ� �ּҰ��Դϴ�. 
	newNode->data = data;
	
	// �� ��尡 �� ��ġ�� ã�� �ݺ����Դϴ�.
	// �񱳰��� 0�̸� ���� 
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
	if(plist->comp == NULL) // ���� ������ ���ٸ� �� �պ��� ������ �����մϴ�. 
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
	plist->cur = plist->head->next; // head�� next�� ù��° �� 
	
	*pdata = plist->cur->data; // ù��° ����� �����͸� ����
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
	Node * rpos = plist->cur; // ������ �ּҰ� 
	LData rdata = rpos->data; // ������ �ּ��� ������
	
	plist->before->next = plist->cur->next; // �� ���ٷ� ���� ���� ���� �����մϴ�.
	plist->cur = plist->before; // ��ġ ������
	
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
	plist->comp = comp; // ���� ������ ����մϴ�. main���� plist�� �Ѱ��� �����մϴ�. 
}
