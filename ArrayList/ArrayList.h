#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100

#include "NameCard.h"
typedef NameCard * LData;

typedef struct _ArrayList {
	LData arr[LIST_LEN]; // ����Ʈ ����� 
	int sizeOfData; // ����� �������� �� 
	int curPosition; // ������ ���� ��ġ 
} ArrayList;

typedef ArrayList List;

void ListInit(List * plist); // ����Ʈ �ʱ�ȭ 
void LInsert(List * plist, LData data); // ������ ���� 

int LFirst(List * plist, LData * pdata); // ù ������ 
int LNext(List * plist, LData * pdata); // �ι�° ������ ���� ������ 

LData LRemove(List * plist); // ������ ���� 
int LCount(List * plist); // ���̼� �� ���� 
#endif
